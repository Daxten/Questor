﻿// ------------------------------------------------------------------------------
//   <copyright from='2010' to='2015' company='THEHACKERWITHIN.COM'>
//     Copyright (c) TheHackerWithin.COM. All Rights Reserved.
//
//     Please look in the accompanying license.htm file for the license that
//     applies to this source code. (a copy can also be found at:
//     http://www.thehackerwithin.com/license.htm)
//   </copyright>
// -------------------------------------------------------------------------------
namespace BuyLPI
{
    using System;
    using System.Linq;
    using System.Threading;
    using DirectEve;
    using InnerSpaceAPI;

    internal class BuyLPI
    {
        private const int WaitMillis = 3500;
        private  long _lastLoyaltyPoints;
        private  DateTime _nextAction;
        private  DateTime _loyaltyPointTimeout;
        private  string _type;
        private  int? _quantity;
        private  int? _totalquantityoforders;
        private  bool _done;
        private  DirectEve _directEve;

        private  void Main(string[] args)
        {
            if (args.Length == 0)
            {
                Log("Syntax:");
                Log("DotNet BuyLPI BuyLPI <TypeName or TypeId> [Quantity]");
                Log("(Quantity is optional)");
                Log("");
                Log("Example:");
                Log("DotNet BuyLPI BuyLPI \"Caldari Navy Mjolnir Torpedo\" 10");
                Log("*OR*");
                Log("DotNet BuyLPI BuyLPI 27339 10");
                return;
            }

            if (args.Length >= 1)
            {
                _type = args[0];
            }

            if (args.Length >= 2)
            {
                int dummy;
                if (!int.TryParse(args[1], out dummy))
                {
                    Log("BuyLPI: Quantity must be an integer, 0 - {0}", int.MaxValue);
                    return;
                }

                if (dummy < 0)
                {
                    Log("BuyLPI: Quantity must be a positive number");
                    return;
                }

                _quantity = dummy;
                _totalquantityoforders = dummy;
            }

            Log("BuyLPI: Starting BuyLPI...");
            _directEve = new DirectEve();
            _directEve.OnFrame += OnFrame;

            // Sleep until we're done
            while (!_done)
                Thread.Sleep(50);

            _directEve.Dispose();
            Log("BuyLPI: BuyLPI finished.");
        }

        private  void Log(string line, params object[] parms)
        {
            line = string.Format(line, parms);
            InnerSpace.Echo(string.Format("{0:HH:mm:ss} {1}", DateTime.Now, line));
        }

        private  void OnFrame(object sender, EventArgs eventArgs)
        {
            if (_done)
                return;

            // Wait for the next action
            if (_nextAction >= DateTime.Now)
            {
                return;
            }

            DirectContainer hangar = _directEve.GetItemHangar();
            if (!hangar.IsReady)
            {
                _nextAction = DateTime.Now.AddMilliseconds(WaitMillis);
                _directEve.ExecuteCommand(DirectCmd.OpenHangarFloor);

                Log("BuyLPI: Opening item hangar");
                return;
            }

            DirectLoyaltyPointStoreWindow lpstore = _directEve.Windows.OfType<DirectLoyaltyPointStoreWindow>().FirstOrDefault();
            if (lpstore == null)
            {
                _nextAction = DateTime.Now.AddMilliseconds(WaitMillis);
                _directEve.ExecuteCommand(DirectCmd.OpenLpstore);

                Log("BuyLPI: Opening loyalty point store");
                return;
            }

            // Wait for the amount of LP to change
            if (_lastLoyaltyPoints == lpstore.LoyaltyPoints)
                return;

            // Do not expect it to be 0 (probably means its reloading)
            if (lpstore.LoyaltyPoints == 0)
            {
                if (_loyaltyPointTimeout < DateTime.Now)
                {
                    Log("BuyLPI: It seems we have no loyalty points left");

                    _done = true;
                    return;
                }
                return;
            }

            _lastLoyaltyPoints = lpstore.LoyaltyPoints;

            // Find the offer
            DirectLoyaltyPointOffer offer = lpstore.Offers.FirstOrDefault(o => o.TypeId.ToString() == _type || string.Compare(o.TypeName, _type, true) == 0);
            if (offer == null)
            {
                Log("BuyLPI: Can't find offer with type name/id: {0}!", _type);

                _done = true;
                return;
            }

            // Check LP
            if (_lastLoyaltyPoints < offer.LoyaltyPointCost)
            {
                Log("BuyLPI: Not enough loyalty points left");

                _done = true;
                return;
            }

            // Check ISK
            if (_directEve.Me.Wealth < offer.IskCost)
            {
                Log("BuyLPI: Not enough ISK left");

                _done = true;
                return;
            }

            // Check items
            foreach (DirectLoyaltyPointOfferRequiredItem requiredItem in offer.RequiredItems)
            {
                DirectItem item = hangar.Items.FirstOrDefault(i => i.TypeId == requiredItem.TypeId);
                if (item == null || item.Quantity < requiredItem.Quantity)
                {
                    Log("Missing {0}x {1}", requiredItem.Quantity, requiredItem.TypeName);
                    _done = true;
                    return;
                }
            }

            // All passed, accept offer
            Log("BuyLPI: Accepting {0}", offer.TypeName, "[ ", _quantity.Value, " ] of [ ", _totalquantityoforders.Value, " ] orders");
            offer.AcceptOffer();

            // Set next action + loyalty point timeout
            _nextAction = DateTime.Now.AddMilliseconds(WaitMillis);
            _loyaltyPointTimeout = DateTime.Now.AddSeconds(10);

            if (_quantity.HasValue)
            {
                _quantity = _quantity.Value - 1;
                if (_quantity.Value <= 0)
                {
                    Log("Quantity limit reached");

                    _done = true;
                    return;
                }
            }
        }
    }
}