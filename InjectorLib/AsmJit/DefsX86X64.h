// AsmJit - Complete JIT Assembler for C++ Language.

// Copyright (c) 2008-2010, Petr Kobalicek <kobalicek.petr@gmail.com>
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

// [Guard]
#ifndef _ASMJIT_DEFSX86X64_H
#define _ASMJIT_DEFSX86X64_H

#if !defined(_ASMJIT_DEFS_H)
#warning "AsmJit/DefsX86X64.h can be only included by AsmJit/Defs.h"
#endif // _ASMJIT_DEFS_H

// [Dependencies]
#include "Build.h"
#include "Util.h"

#include <stdlib.h>
#include <string.h>

// [Api-Begin]
#include "ApiBegin.h"

namespace AsmJit {

//! @addtogroup AsmJit_Core
//! @{

// ============================================================================
// [AsmJit::REG_NUM]
// ============================================================================

//! @var REG_NUM
//! @brief Count of General purpose registers and XMM registers.
//!
//! Count of general purpose registers and XMM registers depends to current
//! bit-mode. If application is compiled for 32-bit platform then this number
//! is 8, 64-bit platforms have 8 extra general purpose and xmm registers (16
//! total).

//! @brief Count of registers.
enum REG_NUM
{
  //! @var REG_NUM_BASE
  //!
  //! Count of general purpose registers and XMM registers depends to current
  //! bit-mode. If application is compiled for 32-bit platform then this number
  //! is 8, 64-bit platforms have 8 extra general purpose and xmm registers (16
  //! total).
#if defined(ASMJIT_X86)
  REG_NUM_BASE = 8,
#else
  REG_NUM_BASE = 16,
#endif // ASMJIT

  //! @brief Count of general purpose registers.
  //!
  //! 8 in 32-bit mode and 16 in 64-bit mode.
  REG_NUM_GP = REG_NUM_BASE,

  //! @brief Count of MM registers (always 8).
  REG_NUM_MM = 8,

  //! @brief Count of FPU stack registers (always 8).
  REG_NUM_FPU = 8,

  //! @brief Count of XMM registers.
  //!
  //! 8 in 32-bit mode and 16 in 64-bit mode.
  REG_NUM_XMM = REG_NUM_BASE
};

// ============================================================================
// [AsmJit::REG_INDEX]
// ============================================================================

//! @brief Valid X86 register indexes.
//!
//! These codes are real, don't miss with @c REG enum! and don't use these
//! values if you are not writing AsmJit code.
enum REG_INDEX
{
  //! @brief Mask for register code (index).
  REG_INDEX_MASK = 0x00FF,

  //! @brief ID for AX/EAX/RAX registers.
  REG_INDEX_EAX = 0,
  //! @brief ID for CX/ECX/RCX registers.
  REG_INDEX_ECX = 1,
  //! @brief ID for DX/EDX/RDX registers.
  REG_INDEX_EDX = 2,
  //! @brief ID for BX/EBX/RBX registers.
  REG_INDEX_EBX = 3,
  //! @brief ID for SP/ESP/RSP registers.
  REG_INDEX_ESP = 4,
  //! @brief ID for BP/EBP/RBP registers.
  REG_INDEX_EBP = 5,
  //! @brief ID for SI/ESI/RSI registers.
  REG_INDEX_ESI = 6,
  //! @brief ID for DI/EDI/RDI registers.
  REG_INDEX_EDI = 7,

#if defined(ASMJIT_X64)
  //! @brief ID for AX/EAX/RAX registers.
  REG_INDEX_RAX = 0,
  //! @brief ID for CX/ECX/RCX registers.
  REG_INDEX_RCX = 1,
  //! @brief ID for DX/EDX/RDX registers.
  REG_INDEX_RDX = 2,
  //! @brief ID for BX/EBX/RBX registers.
  REG_INDEX_RBX = 3,
  //! @brief ID for SP/ESP/RSP registers.
  REG_INDEX_RSP = 4,
  //! @brief ID for BP/EBP/RBP registers.
  REG_INDEX_RBP = 5,
  //! @brief ID for SI/ESI/RSI registers.
  REG_INDEX_RSI = 6,
  //! @brief ID for DI/EDI/RDI registers.
  REG_INDEX_RDI = 7,

  //! @brief ID for r8 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R8 = 8,
  //! @brief ID for R9 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R9 = 9,
  //! @brief ID for R10 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R10 = 10,
  //! @brief ID for R11 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R11 = 11,
  //! @brief ID for R12 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R12 = 12,
  //! @brief ID for R13 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R13 = 13,
  //! @brief ID for R14 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R14 = 14,
  //! @brief ID for R15 register (additional register introduced by 64-bit architecture).
  REG_INDEX_R15 = 15,
#endif // ASMJIT_X64

  //! @brief ID for mm0 register.
  REG_INDEX_MM0 = 0,
  //! @brief ID for mm1 register.
  REG_INDEX_MM1 = 1,
  //! @brief ID for mm2 register.
  REG_INDEX_MM2 = 2,
  //! @brief ID for mm3 register.
  REG_INDEX_MM3 = 3,
  //! @brief ID for mm4 register.
  REG_INDEX_MM4 = 4,
  //! @brief ID for mm5 register.
  REG_INDEX_MM5 = 5,
  //! @brief ID for mm6 register.
  REG_INDEX_MM6 = 6,
  //! @brief ID for mm7 register.
  REG_INDEX_MM7 = 7,

  //! @brief ID for xmm0 register.
  REG_INDEX_XMM0 = 0,
  //! @brief ID for xmm1 register.
  REG_INDEX_XMM1 = 1,
  //! @brief ID for xmm2 register.
  REG_INDEX_XMM2 = 2,
  //! @brief ID for xmm3 register.
  REG_INDEX_XMM3 = 3,
  //! @brief ID for xmm4 register.
  REG_INDEX_XMM4 = 4,
  //! @brief ID for xmm5 register.
  REG_INDEX_XMM5 = 5,
  //! @brief ID for xmm6 register.
  REG_INDEX_XMM6 = 6,
  //! @brief ID for xmm7 register.
  REG_INDEX_XMM7 = 7

#if defined(ASMJIT_X64)
  ,

  //! @brief ID for xmm8 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM8 = 8,
  //! @brief ID for xmm9 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM9 = 9,
  //! @brief ID for xmm10 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM10 = 10,
  //! @brief ID for xmm11 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM11 = 11,
  //! @brief ID for xmm12 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM12 = 12,
  //! @brief ID for xmm13 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM13 = 13,
  //! @brief ID for xmm14 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM14 = 14,
  //! @brief ID for xmm15 register (additional register introduced by 64-bit architecture).
  REG_INDEX_XMM15 = 15
#endif // ASMJIT_X64
};

// ============================================================================
// [AsmJit::REG_TYPE]
// ============================================================================

//! @brief Pseudo (not real X86) register types.
enum REG_TYPE
{
  //! @brief Mask for register type.
  REG_TYPE_MASK = 0xFF00,

  // First byte contains register type (mask 0xFF00), Second byte contains
  // register index code.

  // --------------------------------------------------------------------------
  // [GP Register Types]
  // --------------------------------------------------------------------------

  //! @brief 8-bit general purpose register type (LO).
  REG_TYPE_GPB_LO = 0x0100,
  //! @brief 8-bit general purpose register type (HI, only AH, BH, CH, DH).
  REG_TYPE_GPB_HI = 0x0200,
  //! @brief 16-bit general purpose register type.
  REG_TYPE_GPW = 0x1000,
  //! @brief 32-bit general purpose register type.
  REG_TYPE_GPD = 0x2000,
  //! @brief 64-bit general purpose register type.
  REG_TYPE_GPQ = 0x3000,

  //! @var REG_GPN
  //! @brief 32-bit or 64-bit general purpose register type.

  // native 32-bit or 64-bit register type (depends to x86 or x64 mode).
#if defined(ASMJIT_X86)
  REG_TYPE_GPN = REG_TYPE_GPD,
#else
  REG_TYPE_GPN = REG_TYPE_GPQ,
#endif

  // --------------------------------------------------------------------------
  // [X87 (FPU) Register Type]
  // --------------------------------------------------------------------------

  //! @brief X87 (FPU) register type.
  REG_TYPE_X87 = 0x5000,

  // --------------------------------------------------------------------------
  // [MM Register Type]
  // --------------------------------------------------------------------------

  //! @brief 64-bit MM register type.
  REG_TYPE_MM = 0x6000,

  // --------------------------------------------------------------------------
  // [XMM Register Type]
  // --------------------------------------------------------------------------

  //! @brief 128-bit XMM register type.
  REG_TYPE_XMM = 0x7000
};

// ============================================================================
// [AsmJit::REG_CODE]
// ============================================================================

//! @brief Pseudo (not real X86) register codes used for generating opcodes.
//!
//! From this register code can be generated real x86 register ID, type of
//! register and size of register.
enum REG_CODE
{
  // --------------------------------------------------------------------------
  // [8-bit Registers]
  // --------------------------------------------------------------------------

  REG_AL = REG_TYPE_GPB_LO,
  REG_CL,
  REG_DL,
  REG_BL,
#if defined(ASMJIT_X64)
  REG_SPL,
  REG_BPL,
  REG_SIL,
  REG_DIL,
#endif // ASMJIT_X64

#if defined(ASMJIT_X64)
  REG_R8B,
  REG_R9B,
  REG_R10B,
  REG_R11B,
  REG_R12B,
  REG_R13B,
  REG_R14B,
  REG_R15B,
#endif // ASMJIT_X64

  REG_AH = REG_TYPE_GPB_HI,
  REG_CH,
  REG_DH,
  REG_BH,

  // --------------------------------------------------------------------------
  // [16-bit Registers]
  // --------------------------------------------------------------------------

  REG_AX = REG_TYPE_GPW,
  REG_CX,
  REG_DX,
  REG_BX,
  REG_SP,
  REG_BP,
  REG_SI,
  REG_DI,
#if defined(ASMJIT_X64)
  REG_R8W,
  REG_R9W,
  REG_R10W,
  REG_R11W,
  REG_R12W,
  REG_R13W,
  REG_R14W,
  REG_R15W,
#endif // ASMJIT_X64

  // --------------------------------------------------------------------------
  // [32-bit Registers]
  // --------------------------------------------------------------------------

  REG_EAX = REG_TYPE_GPD,
  REG_ECX,
  REG_EDX,
  REG_EBX,
  REG_ESP,
  REG_EBP,
  REG_ESI,
  REG_EDI,
#if defined(ASMJIT_X64)
  REG_R8D,
  REG_R9D,
  REG_R10D,
  REG_R11D,
  REG_R12D,
  REG_R13D,
  REG_R14D,
  REG_R15D,
#endif // ASMJIT_X64

  // --------------------------------------------------------------------------
  // [64-bit Registers]
  // --------------------------------------------------------------------------

#if defined(ASMJIT_X64)
  REG_RAX = REG_TYPE_GPQ,
  REG_RCX,
  REG_RDX,
  REG_RBX,
  REG_RSP,
  REG_RBP,
  REG_RSI,
  REG_RDI,
  REG_R8,
  REG_R9,
  REG_R10,
  REG_R11,
  REG_R12,
  REG_R13,
  REG_R14,
  REG_R15,
#endif // ASMJIT_X64

  // --------------------------------------------------------------------------
  // [MM Registers]
  // --------------------------------------------------------------------------

  REG_MM0 = REG_TYPE_MM,
  REG_MM1,
  REG_MM2,
  REG_MM3,
  REG_MM4,
  REG_MM5,
  REG_MM6,
  REG_MM7,

  // --------------------------------------------------------------------------
  // [XMM Registers]
  // --------------------------------------------------------------------------

  REG_XMM0 = REG_TYPE_XMM,
  REG_XMM1,
  REG_XMM2,
  REG_XMM3,
  REG_XMM4,
  REG_XMM5,
  REG_XMM6,
  REG_XMM7,
#if defined(ASMJIT_X64)
  REG_XMM8,
  REG_XMM9,
  REG_XMM10,
  REG_XMM11,
  REG_XMM12,
  REG_XMM13,
  REG_XMM14,
  REG_XMM15,
#endif // ASMJIT_X64

  // --------------------------------------------------------------------------
  // [Native registers (depends if processor runs in 32-bit or 64-bit mode)]
  // --------------------------------------------------------------------------

  REG_NAX = REG_TYPE_GPN,
  REG_NCX,
  REG_NDX,
  REG_NBX,
  REG_NSP,
  REG_NBP,
  REG_NSI,
  REG_NDI
};

// ============================================================================
// [AsmJit::SEGMENT_PREFIX]
// ============================================================================

//! @brief Segment override prefixes.
enum SEGMENT_PREFIX
{
  // DO NOT MODIFY INDEX CODES - They are used by logger in this order.

  //! @brief No segment override prefix.
  SEGMENT_NONE = 0,
  //! @brief Use 'cs' segment override prefix.
  SEGMENT_CS = 1,
  //! @brief Use 'ss' segment override prefix.
  SEGMENT_SS = 2,
  //! @brief Use 'ds' segment override prefix.
  SEGMENT_DS = 3,
  //! @brief Use 'es' segment override prefix.
  SEGMENT_ES = 4,
  //! @brief Use 'fs' segment override prefix.
  SEGMENT_FS = 5,
  //! @brief Use 'gs' segment override prefix.
  SEGMENT_GS = 6,
  //! @brief End of prefix codes
  _SEGMENT_END
};

// ============================================================================
// [AsmJit::PREFETCH_HINT]
// ============================================================================

//! @brief Prefetch hints.
enum PREFETCH_HINT
{
  //! @brief Prefetch to L0 cache.
  PREFETCH_T0  = 1,
  //! @brief Prefetch to L1 cache.
  PREFETCH_T1  = 2,
  //! @brief Prefetch to L2 cache.
  PREFETCH_T2  = 3,
  //! @brief Prefetch using NT hint.
  PREFETCH_NTA = 0
};

// ============================================================================
// [AsmJit::CONDITION]
// ============================================================================

//! @brief Condition codes.
enum CONDITION
{
  //! @brief No condition code.
  C_NO_CONDITION  = -1,

  // Condition codes from processor manuals.
  C_A             = 0x7,
  C_AE            = 0x3,
  C_B             = 0x2,
  C_BE            = 0x6,
  C_C             = 0x2,
  C_E             = 0x4,
  C_G             = 0xF,
  C_GE            = 0xD,
  C_L             = 0xC,
  C_LE            = 0xE,
  C_NA            = 0x6,
  C_NAE           = 0x2,
  C_NB            = 0x3,
  C_NBE           = 0x7,
  C_NC            = 0x3,
  C_NE            = 0x5,
  C_NG            = 0xE,
  C_NGE           = 0xC,
  C_NL            = 0xD,
  C_NLE           = 0xF,
  C_NO            = 0x1,
  C_NP            = 0xB,
  C_NS            = 0x9,
  C_NZ            = 0x5,
  C_O             = 0x0,
  C_P             = 0xA,
  C_PE            = 0xA,
  C_PO            = 0xB,
  C_S             = 0x8,
  C_Z             = 0x4,

  // Simplified condition codes
  C_OVERFLOW      = 0x0,
  C_NO_OVERFLOW   = 0x1,
  C_BELOW         = 0x2,
  C_ABOVE_EQUAL   = 0x3,
  C_EQUAL         = 0x4,
  C_NOT_EQUAL     = 0x5,
  C_BELOW_EQUAL   = 0x6,
  C_ABOVE         = 0x7,
  C_SIGN          = 0x8,
  C_NOT_SIGN      = 0x9,
  C_PARITY_EVEN   = 0xA,
  C_PARITY_ODD    = 0xB,
  C_LESS          = 0xC,
  C_GREATER_EQUAL = 0xD,
  C_LESS_EQUAL    = 0xE,
  C_GREATER       = 0xF,

  // aliases
  C_ZERO          = 0x4,
  C_NOT_ZERO      = 0x5,
  C_NEGATIVE      = 0x8,
  C_POSITIVE      = 0x9,

  // x87 floating point only
  C_FP_UNORDERED  = 16,
  C_FP_NOT_UNORDERED = 17
};

//! @brief  Returns the equivalent of !cc.
//!
//! Negation of the default no_condition (-1) results in a non-default
//! no_condition value (-2). As long as tests for no_condition check
//! for condition < 0, this will work as expected.
static inline CONDITION negateCondition(CONDITION cc)
{
  return static_cast<CONDITION>(cc ^ 1);
}

//! @brief Corresponds to transposing the operands of a comparison.
static inline CONDITION reverseCondition(CONDITION cc)
{
  switch (cc) {
    case C_BELOW:
      return C_ABOVE;
    case C_ABOVE:
      return C_BELOW;
    case C_ABOVE_EQUAL:
      return C_BELOW_EQUAL;
    case C_BELOW_EQUAL:
      return C_ABOVE_EQUAL;
    case C_LESS:
      return C_GREATER;
    case C_GREATER:
      return C_LESS;
    case C_GREATER_EQUAL:
      return C_LESS_EQUAL;
    case C_LESS_EQUAL:
      return C_GREATER_EQUAL;
    default:
      return cc;
  };
}

struct ASMJIT_API ConditionToInstruction
{
  //! @brief Used to map condition code to jcc instructions.
  static const uint32_t _jcctable[16];
  //! @brief Used to map condition code to cmovcc instructions.
  static const uint32_t _cmovcctable[16];
  //! @brief Used to map condition code to setcc instructions.
  static const uint32_t _setcctable[16];

  //! @brief Translate condition code @a cc to jcc instruction code.
  //! @sa @c INST_CODE, @c INST_J.
  static inline uint32_t toJCC(CONDITION cc) ASMJIT_NOTHROW
  {
    ASMJIT_ASSERT(static_cast<uint32_t>(cc) <= 0xF);
    return _jcctable[cc];
  }

  //! @brief Translate condition code @a cc to cmovcc instruction code.
  //! @sa @c INST_CODE, @c INST_CMOV.
  static inline uint32_t toCMovCC(CONDITION cc) ASMJIT_NOTHROW
  {
    ASMJIT_ASSERT(static_cast<uint32_t>(cc) <= 0xF);
    return _cmovcctable[cc];
  }

  //! @brief Translate condition code @a cc to setcc instruction code.
  //! @sa @c INST_CODE, @c INST_SET.
  static inline uint32_t toSetCC(CONDITION cc) ASMJIT_NOTHROW
  {
    ASMJIT_ASSERT(static_cast<uint32_t>(cc) <= 0xF);
    return _setcctable[cc];
  }
};

// ============================================================================
// [AsmJit::SCALE]
// ============================================================================

//! @brief Scale, can be used for addressing.
//!
//! See @c Op and addressing methods like @c byte_ptr(), @c word_ptr(),
//! @c dword_ptr(), etc...
enum SCALE
{
  //! @brief Scale 1 times (no scale).
  TIMES_1 = 0,
  //! @brief Scale 2 times (same as shifting to left by 1).
  TIMES_2 = 1,
  //! @brief Scale 4 times (same as shifting to left by 2).
  TIMES_4 = 2,
  //! @brief Scale 8 times (same as shifting to left by 3).
  TIMES_8 = 3
};

// ============================================================================
// [AsmJit::HINT]
// ============================================================================

//! @brief Condition hint, see @c AsmJit::Assembler::jz(), @c AsmJit::Compiler::jz()
//! and friends.
enum HINT
{
  //! @brief No hint.
  HINT_NONE = 0x00,
  //! @brief Condition will be taken (likely).
  HINT_TAKEN = 0x01,
  //! @brief Condition will be not taken (unlikely).
  HINT_NOT_TAKEN = 0x02
};

//! @brief Hint byte value is the byte that will be emitted if hint flag
//! is specified by @c HINT.
enum HINT_BYTE_VALUE
{
  //! @brief Condition will be taken (likely).
  HINT_BYTE_VALUE_TAKEN = 0x3E,
  //! @brief Condition will be not taken (unlikely).
  HINT_BYTE_VALUE_NOT_TAKEN = 0x2E
};

// ============================================================================
// [AsmJit::FP_STATUS]
// ============================================================================

//! @brief Floating point status.
enum FP_STATUS
{
  FP_C0 = 0x100,
  FP_C1 = 0x200,
  FP_C2 = 0x400,
  FP_C3 = 0x4000,
  FP_CC_MASK = 0x4500
};

// ============================================================================
// [AsmJit::FP_CW]
// ============================================================================

//! @brief Floating point control word.
enum FP_CW
{
  FP_CW_INVOPEX_MASK  = 0x001,
  FP_CW_DENOPEX_MASK  = 0x002,
  FP_CW_ZERODIV_MASK  = 0x004,
  FP_CW_OVFEX_MASK    = 0x008,
  FP_CW_UNDFEX_MASK   = 0x010,
  FP_CW_PRECEX_MASK   = 0x020,
  FP_CW_PRECC_MASK    = 0x300,
  FP_CW_ROUNDC_MASK   = 0xC00,

  // Values for precision control.
  FP_CW_PREC_SINGLE   = 0x000,
  FP_CW_PREC_DOUBLE   = 0x200,
  FP_CW_PREC_EXTENDED = 0x300,

  // Values for rounding control.
  FP_CW_ROUND_NEAREST = 0x000,
  FP_CW_ROUND_DOWN    = 0x400,
  FP_CW_ROUND_UP      = 0x800,
  FP_CW_ROUND_TOZERO  = 0xC00
};

// ============================================================================
// [AsmJit::INST_CODE]
// ============================================================================

//! @brief Instruction codes.
//!
//! Note that these instruction codes are AsmJit specific. Each instruction is
//! unique ID into AsmJit instruction table. Instruction codes are used together
//! with AsmJit::Assembler and you can also use instruction codes to serialize
//! instructions by @ref AssemblerCore::_emitInstruction() or
//! @ref CompilerCore::_emitInstruction()
enum INST_CODE
{
  INST_ADC,           // X86/X64
  INST_ADD,           // X86/X64
  INST_ADDPD,
  INST_ADDPS,
  INST_ADDSD,
  INST_ADDSS,
  INST_ADDSUBPD,
  INST_ADDSUBPS,
  INST_AMD_PREFETCH,
  INST_AMD_PREFETCHW,
  INST_AND,           // X86/X64
  INST_ANDNPD,
  INST_ANDNPS,
  INST_ANDPD,
  INST_ANDPS,
  INST_BLENDPD,
  INST_BLENDPS,
  INST_BLENDVPD,
  INST_BLENDVPS,
  INST_BSF,           // X86/X64
  INST_BSR,           // X86/X64
  INST_BSWAP,         // X86/X64 (i486)
  INST_BT,            // X86/X64
  INST_BTC,           // X86/X64
  INST_BTR,           // X86/X64
  INST_BTS,           // X86/X64
  INST_CALL,          // X86/X64
  INST_CBW,           // X86/X64
  INST_CDQE,          // X64 only
  INST_CLC,           // X86/X64
  INST_CLD,           // X86/X64
  INST_CLFLUSH,
  INST_CMC,           // X86/X64

  INST_CMOV,          // Begin (cmovcc) (i586)
  INST_CMOVA = INST_CMOV, //X86/X64 (cmovcc) (i586)
  INST_CMOVAE,        // X86/X64 (cmovcc) (i586)
  INST_CMOVB,         // X86/X64 (cmovcc) (i586)
  INST_CMOVBE,        // X86/X64 (cmovcc) (i586)
  INST_CMOVC,         // X86/X64 (cmovcc) (i586)
  INST_CMOVE,         // X86/X64 (cmovcc) (i586)
  INST_CMOVG,         // X86/X64 (cmovcc) (i586)
  INST_CMOVGE,        // X86/X64 (cmovcc) (i586)
  INST_CMOVL,         // X86/X64 (cmovcc) (i586)
  INST_CMOVLE,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNA,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNAE,       // X86/X64 (cmovcc) (i586)
  INST_CMOVNB,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNBE,       // X86/X64 (cmovcc) (i586)
  INST_CMOVNC,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNE,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNG,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNGE,       // X86/X64 (cmovcc) (i586)
  INST_CMOVNL,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNLE,       // X86/X64 (cmovcc) (i586)
  INST_CMOVNO,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNP,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNS,        // X86/X64 (cmovcc) (i586)
  INST_CMOVNZ,        // X86/X64 (cmovcc) (i586)
  INST_CMOVO,         // X86/X64 (cmovcc) (i586)
  INST_CMOVP,         // X86/X64 (cmovcc) (i586)
  INST_CMOVPE,        // X86/X64 (cmovcc) (i586)
  INST_CMOVPO,        // X86/X64 (cmovcc) (i586)
  INST_CMOVS,         // X86/X64 (cmovcc) (i586)
  INST_CMOVZ,         // X86/X64 (cmovcc) (i586)

  INST_CMP,           // X86/X64
  INST_CMPPD,
  INST_CMPPS,
  INST_CMPSD,
  INST_CMPSS,
  INST_CMPXCHG,       // X86/X64 (i486)
  INST_CMPXCHG16B,    // X64 only
  INST_CMPXCHG8B,     // X86/X64 (i586)
  INST_COMISD,
  INST_COMISS,
  INST_CPUID,         // X86/X64 (i486)
  INST_CRC32,
  INST_CVTDQ2PD,
  INST_CVTDQ2PS,
  INST_CVTPD2DQ,
  INST_CVTPD2PI,
  INST_CVTPD2PS,
  INST_CVTPI2PD,
  INST_CVTPI2PS,
  INST_CVTPS2DQ,
  INST_CVTPS2PD,
  INST_CVTPS2PI,
  INST_CVTSD2SI,
  INST_CVTSD2SS,
  INST_CVTSI2SD,
  INST_CVTSI2SS,
  INST_CVTSS2SD,
  INST_CVTSS2SI,
  INST_CVTTPD2DQ,
  INST_CVTTPD2PI,
  INST_CVTTPS2DQ,
  INST_CVTTPS2PI,
  INST_CVTTSD2SI,
  INST_CVTTSS2SI,
  INST_CWDE,          // X86/X64
  INST_DAA,           // X86 only
  INST_DAS,           // X86 only
  INST_DEC,           // X86/X64
  INST_DIV,           // X86/X64
  INST_DIVPD,
  INST_DIVPS,
  INST_DIVSD,
  INST_DIVSS,
  INST_DPPD,
  INST_DPPS,
  INST_EMMS,          // MMX
  INST_ENTER,         // X86/X64
  INST_EXTRACTPS,
  INST_F2XM1,         // X87
  INST_FABS,          // X87
  INST_FADD,          // X87
  INST_FADDP,         // X87
  INST_FBLD,          // X87
  INST_FBSTP,         // X87
  INST_FCHS,          // X87
  INST_FCLEX,         // X87
  INST_FCMOVB,        // X87
  INST_FCMOVBE,       // X87
  INST_FCMOVE,        // X87
  INST_FCMOVNB,       // X87
  INST_FCMOVNBE,      // X87
  INST_FCMOVNE,       // X87
  INST_FCMOVNU,       // X87
  INST_FCMOVU,        // X87
  INST_FCOM,          // X87
  INST_FCOMI,         // X87
  INST_FCOMIP,        // X87
  INST_FCOMP,         // X87
  INST_FCOMPP,        // X87
  INST_FCOS,          // X87
  INST_FDECSTP,       // X87
  INST_FDIV,          // X87
  INST_FDIVP,         // X87
  INST_FDIVR,         // X87
  INST_FDIVRP,        // X87
  INST_FEMMS,         // 3dNow!
  INST_FFREE,         // X87
  INST_FIADD,         // X87
  INST_FICOM,         // X87
  INST_FICOMP,        // X87
  INST_FIDIV,         // X87
  INST_FIDIVR,        // X87
  INST_FILD,          // X87
  INST_FIMUL,         // X87
  INST_FINCSTP,       // X87
  INST_FINIT,         // X87
  INST_FIST,          // X87
  INST_FISTP,         // X87
  INST_FISTTP,
  INST_FISUB,         // X87
  INST_FISUBR,        // X87
  INST_FLD,           // X87
  INST_FLD1,          // X87
  INST_FLDCW,         // X87
  INST_FLDENV,        // X87
  INST_FLDL2E,        // X87
  INST_FLDL2T,        // X87
  INST_FLDLG2,        // X87
  INST_FLDLN2,        // X87
  INST_FLDPI,         // X87
  INST_FLDZ,          // X87
  INST_FMUL,          // X87
  INST_FMULP,         // X87
  INST_FNCLEX,        // X87
  INST_FNINIT,        // X87
  INST_FNOP,          // X87
  INST_FNSAVE,        // X87
  INST_FNSTCW,        // X87
  INST_FNSTENV,       // X87
  INST_FNSTSW,        // X87
  INST_FPATAN,        // X87
  INST_FPREM,         // X87
  INST_FPREM1,        // X87
  INST_FPTAN,         // X87
  INST_FRNDINT,       // X87
  INST_FRSTOR,        // X87
  INST_FSAVE,         // X87
  INST_FSCALE,        // X87
  INST_FSIN,          // X87
  INST_FSINCOS,       // X87
  INST_FSQRT,         // X87
  INST_FST,           // X87
  INST_FSTCW,         // X87
  INST_FSTENV,        // X87
  INST_FSTP,          // X87
  INST_FSTSW,         // X87
  INST_FSUB,          // X87
  INST_FSUBP,         // X87
  INST_FSUBR,         // X87
  INST_FSUBRP,        // X87
  INST_FTST,          // X87
  INST_FUCOM,         // X87
  INST_FUCOMI,        // X87
  INST_FUCOMIP,       // X87
  INST_FUCOMP,        // X87
  INST_FUCOMPP,       // X87
  INST_FWAIT,         // X87
  INST_FXAM,          // X87
  INST_FXCH,          // X87
  INST_FXRSTOR,       // X87
  INST_FXSAVE,        // X87
  INST_FXTRACT,       // X87
  INST_FYL2X,         // X87
  INST_FYL2XP1,       // X87
  INST_HADDPD,
  INST_HADDPS,
  INST_HSUBPD,
  INST_HSUBPS,
  INST_IDIV,          // X86/X64
  INST_IMUL,          // X86/X64
  INST_INC,           // X86/X64
  INST_INT3,          // X86/X64
  INST_J,             // Begin (jcc)
  INST_JA = 
    INST_J,           // X86/X64 (jcc)
  INST_JAE,           // X86/X64 (jcc)
  INST_JB,            // X86/X64 (jcc)
  INST_JBE,           // X86/X64 (jcc)
  INST_JC,            // X86/X64 (jcc)
  INST_JE,            // X86/X64 (jcc)
  INST_JG,            // X86/X64 (jcc)
  INST_JGE,           // X86/X64 (jcc)
  INST_JL,            // X86/X64 (jcc)
  INST_JLE,           // X86/X64 (jcc)
  INST_JNA,           // X86/X64 (jcc)
  INST_JNAE,          // X86/X64 (jcc)
  INST_JNB,           // X86/X64 (jcc)
  INST_JNBE,          // X86/X64 (jcc)
  INST_JNC,           // X86/X64 (jcc)
  INST_JNE,           // X86/X64 (jcc)
  INST_JNG,           // X86/X64 (jcc)
  INST_JNGE,          // X86/X64 (jcc)
  INST_JNL,           // X86/X64 (jcc)
  INST_JNLE,          // X86/X64 (jcc)
  INST_JNO,           // X86/X64 (jcc)
  INST_JNP,           // X86/X64 (jcc)
  INST_JNS,           // X86/X64 (jcc)
  INST_JNZ,           // X86/X64 (jcc)
  INST_JO,            // X86/X64 (jcc)
  INST_JP,            // X86/X64 (jcc)
  INST_JPE,           // X86/X64 (jcc)
  INST_JPO,           // X86/X64 (jcc)
  INST_JS,            // X86/X64 (jcc)
  INST_JZ,            // X86/X64 (jcc)
  INST_JMP,           // X86/X64 (jmp)
  INST_LDDQU,
  INST_LDMXCSR,
  INST_LAHF,          // X86/X64 (CPUID NEEDED)
  INST_LEA,           // X86/X64
  INST_LEAVE,         // X86/X64
  INST_LFENCE,
  INST_MASKMOVDQU,
  INST_MASKMOVQ,      // MMX Extensions
  INST_MAXPD,
  INST_MAXPS,
  INST_MAXSD,
  INST_MAXSS,
  INST_MFENCE,
  INST_MINPD,
  INST_MINPS,
  INST_MINSD,
  INST_MINSS,
  INST_MONITOR,
  INST_MOV,           // X86/X64
  INST_MOVAPD,
  INST_MOVAPS,
  INST_MOVBE,
  INST_MOVD,
  INST_MOVDDUP,
  INST_MOVDQ2Q,
  INST_MOVDQA,
  INST_MOVDQU,
  INST_MOVHLPS,
  INST_MOVHPD,
  INST_MOVHPS,
  INST_MOVLHPS,
  INST_MOVLPD,
  INST_MOVLPS,
  INST_MOVMSKPD,
  INST_MOVMSKPS,
  INST_MOVNTDQ,
  INST_MOVNTDQA,
  INST_MOVNTI,
  INST_MOVNTPD,
  INST_MOVNTPS,
  INST_MOVNTQ,        // MMX Extensions
  INST_MOVQ,
  INST_MOVQ2DQ,
  INST_MOVSD,
  INST_MOVSHDUP,
  INST_MOVSLDUP,
  INST_MOVSS,
  INST_MOVSX,         // X86/X64
  INST_MOVSXD,        // X86/X64
  INST_MOVUPD,
  INST_MOVUPS,
  INST_MOVZX,         // X86/X64
  INST_MOV_PTR,       // X86/X64
  INST_MPSADBW,
  INST_MUL,           // X86/X64
  INST_MULPD,
  INST_MULPS,
  INST_MULSD,
  INST_MULSS,
  INST_MWAIT,
  INST_NEG,           // X86/X64
  INST_NOP,           // X86/X64
  INST_NOT,           // X86/X64
  INST_OR,            // X86/X64
  INST_ORPD,
  INST_ORPS,
  INST_PABSB,
  INST_PABSD,
  INST_PABSW,
  INST_PACKSSDW,
  INST_PACKSSWB,
  INST_PACKUSDW,
  INST_PACKUSWB,
  INST_PADDB,
  INST_PADDD,
  INST_PADDQ,
  INST_PADDSB,
  INST_PADDSW,
  INST_PADDUSB,
  INST_PADDUSW,
  INST_PADDW,
  INST_PALIGNR,
  INST_PAND,
  INST_PANDN,
  INST_PAUSE,
  INST_PAVGB,         // MMX Extensions
  INST_PAVGW,         // MMX Extensions
  INST_PBLENDVB,
  INST_PBLENDW,
  INST_PCMPEQB,
  INST_PCMPEQD,
  INST_PCMPEQQ,
  INST_PCMPEQW,
  INST_PCMPESTRI,
  INST_PCMPESTRM,
  INST_PCMPGTB,
  INST_PCMPGTD,
  INST_PCMPGTQ,
  INST_PCMPGTW,
  INST_PCMPISTRI,
  INST_PCMPISTRM,
  INST_PEXTRB,
  INST_PEXTRD,
  INST_PEXTRQ,
  INST_PEXTRW,        // MMX Extensions
  INST_PF2ID,         // 3dNow!
  INST_PF2IW,         // 3dNow! Extensions
  INST_PFACC,         // 3dNow!
  INST_PFADD,         // 3dNow!
  INST_PFCMPEQ,       // 3dNow!
  INST_PFCMPGE,       // 3dNow!
  INST_PFCMPGT,       // 3dNow!
  INST_PFMAX,         // 3dNow!
  INST_PFMIN,         // 3dNow!
  INST_PFMUL,         // 3dNow!
  INST_PFNACC,        // 3dNow! Extensions
  INST_PFPNACC,       // 3dNow! Extensions
  INST_PFRCP,         // 3dNow!
  INST_PFRCPIT1,      // 3dNow!
  INST_PFRCPIT2,      // 3dNow!
  INST_PFRSQIT1,      // 3dNow!
  INST_PFRSQRT,       // 3dNow!
  INST_PFSUB,         // 3dNow!
  INST_PFSUBR,        // 3dNow!
  INST_PHADDD,
  INST_PHADDSW,
  INST_PHADDW,
  INST_PHMINPOSUW,
  INST_PHSUBD,
  INST_PHSUBSW,
  INST_PHSUBW,
  INST_PI2FD,         // 3dNow!
  INST_PI2FW,         // 3dNow! Extensions
  INST_PINSRB,
  INST_PINSRD,
  INST_PINSRQ,
  INST_PINSRW,        // MMX Extensions
  INST_PMADDUBSW,
  INST_PMADDWD,
  INST_PMAXSB,
  INST_PMAXSD,
  INST_PMAXSW,        // MMX Extensions
  INST_PMAXUB,        // MMX Extensions
  INST_PMAXUD,
  INST_PMAXUW,
  INST_PMINSB,
  INST_PMINSD,
  INST_PMINSW,        // MMX Extensions
  INST_PMINUB,        // MMX Extensions
  INST_PMINUD,
  INST_PMINUW,
  INST_PMOVMSKB,      // MMX Extensions
  INST_PMOVSXBD,
  INST_PMOVSXBQ,
  INST_PMOVSXBW,
  INST_PMOVSXDQ,
  INST_PMOVSXWD,
  INST_PMOVSXWQ,
  INST_PMOVZXBD,
  INST_PMOVZXBQ,
  INST_PMOVZXBW,
  INST_PMOVZXDQ,
  INST_PMOVZXWD,
  INST_PMOVZXWQ,
  INST_PMULDQ,
  INST_PMULHRSW,
  INST_PMULHUW,       // MMX Extensions
  INST_PMULHW,
  INST_PMULLD,
  INST_PMULLW,
  INST_PMULUDQ,
  INST_POP,           // X86/X64
  INST_POPAD,         // X86 only
  INST_POPCNT,
  INST_POPFD,         // X86 only
  INST_POPFQ,         // X64 only
  INST_POR,
  INST_PREFETCH,      // MMX Extensions
  INST_PSADBW,        // MMX Extensions
  INST_PSHUFB,
  INST_PSHUFD,
  INST_PSHUFW,        // MMX Extensions
  INST_PSHUFHW,
  INST_PSHUFLW,
  INST_PSIGNB,
  INST_PSIGND,
  INST_PSIGNW,
  INST_PSLLD,
  INST_PSLLDQ,
  INST_PSLLQ,
  INST_PSLLW,
  INST_PSRAD,
  INST_PSRAW,
  INST_PSRLD,
  INST_PSRLDQ,
  INST_PSRLQ,
  INST_PSRLW,
  INST_PSUBB,
  INST_PSUBD,
  INST_PSUBQ,
  INST_PSUBSB,
  INST_PSUBSW,
  INST_PSUBUSB,
  INST_PSUBUSW,
  INST_PSUBW,
  INST_PSWAPD,        // 3dNow! Extensions
  INST_PTEST,
  INST_PUNPCKHBW,
  INST_PUNPCKHDQ,
  INST_PUNPCKHQDQ,
  INST_PUNPCKHWD,
  INST_PUNPCKLBW,
  INST_PUNPCKLDQ,
  INST_PUNPCKLQDQ,
  INST_PUNPCKLWD,
  INST_PUSH,          // X86/X64
  INST_PUSHAD,        // X86 only
  INST_PUSHFD,        // X86 only
  INST_PUSHFQ,        // X64 only
  INST_PXOR,
  INST_RCL,           // X86/X64
  INST_RCPPS,
  INST_RCPSS,
  INST_RCR,           // X86/X64
  INST_RDTSC,         // X86/X64
  INST_RDTSCP,        // X86/X64
  INST_REP_LODSB,     // X86/X64 (REP)
  INST_REP_LODSD,     // X86/X64 (REP)
  INST_REP_LODSQ,     // X64 only (REP)
  INST_REP_LODSW,     // X86/X64 (REP)
  INST_REP_MOVSB,     // X86/X64 (REP)
  INST_REP_MOVSD,     // X86/X64 (REP)
  INST_REP_MOVSQ,     // X64 only (REP)
  INST_REP_MOVSW,     // X86/X64 (REP)
  INST_REP_STOSB,     // X86/X64 (REP)
  INST_REP_STOSD,     // X86/X64 (REP)
  INST_REP_STOSQ,     // X64 only (REP)
  INST_REP_STOSW,     // X86/X64 (REP)
  INST_REPE_CMPSB,    // X86/X64 (REP)
  INST_REPE_CMPSD,    // X86/X64 (REP)
  INST_REPE_CMPSQ,    // X64 only (REP)
  INST_REPE_CMPSW,    // X86/X64 (REP)
  INST_REPE_SCASB,    // X86/X64 (REP)
  INST_REPE_SCASD,    // X86/X64 (REP)
  INST_REPE_SCASQ,    // X64 only (REP)
  INST_REPE_SCASW,    // X86/X64 (REP)
  INST_REPNE_CMPSB,   // X86/X64 (REP)
  INST_REPNE_CMPSD,   // X86/X64 (REP)
  INST_REPNE_CMPSQ,   // X64 only (REP)
  INST_REPNE_CMPSW,   // X86/X64 (REP)
  INST_REPNE_SCASB,   // X86/X64 (REP)
  INST_REPNE_SCASD,   // X86/X64 (REP)
  INST_REPNE_SCASQ,   // X64 only (REP)
  INST_REPNE_SCASW,   // X86/X64 (REP)
  INST_RET,           // X86/X64
  INST_ROL,           // X86/X64
  INST_ROR,           // X86/X64
  INST_ROUNDPD,
  INST_ROUNDPS,
  INST_ROUNDSD,
  INST_ROUNDSS,
  INST_RSQRTPS,
  INST_RSQRTSS,
  INST_SAHF,          // X86/X64 (CPUID NEEDED)
  INST_SAL,           // X86/X64
  INST_SAR,           // X86/X64
  INST_SBB,           // X86/X64
  INST_SET,           // Begin (setcc)
  INST_SETA=INST_SET, // X86/X64 (setcc)
  INST_SETAE,         // X86/X64 (setcc)
  INST_SETB,          // X86/X64 (setcc)
  INST_SETBE,         // X86/X64 (setcc)
  INST_SETC,          // X86/X64 (setcc)
  INST_SETE,          // X86/X64 (setcc)
  INST_SETG,          // X86/X64 (setcc)
  INST_SETGE,         // X86/X64 (setcc)
  INST_SETL,          // X86/X64 (setcc)
  INST_SETLE,         // X86/X64 (setcc)
  INST_SETNA,         // X86/X64 (setcc)
  INST_SETNAE,        // X86/X64 (setcc)
  INST_SETNB,         // X86/X64 (setcc)
  INST_SETNBE,        // X86/X64 (setcc)
  INST_SETNC,         // X86/X64 (setcc)
  INST_SETNE,         // X86/X64 (setcc)
  INST_SETNG,         // X86/X64 (setcc)
  INST_SETNGE,        // X86/X64 (setcc)
  INST_SETNL,         // X86/X64 (setcc)
  INST_SETNLE,        // X86/X64 (setcc)
  INST_SETNO,         // X86/X64 (setcc)
  INST_SETNP,         // X86/X64 (setcc)
  INST_SETNS,         // X86/X64 (setcc)
  INST_SETNZ,         // X86/X64 (setcc)
  INST_SETO,          // X86/X64 (setcc)
  INST_SETP,          // X86/X64 (setcc)
  INST_SETPE,         // X86/X64 (setcc)
  INST_SETPO,         // X86/X64 (setcc)
  INST_SETS,          // X86/X64 (setcc)
  INST_SETZ,          // X86/X64 (setcc)
  INST_SFENCE,        // MMX Extensions
  INST_SHL,           // X86/X64
  INST_SHLD,          // X86/X64
  INST_SHR,           // X86/X64
  INST_SHRD,          // X86/X64
  INST_SHUFPD,
  INST_SHUFPS,
  INST_SQRTPD,
  INST_SQRTPS,
  INST_SQRTSD,
  INST_SQRTSS,
  INST_STC,           // X86/X64
  INST_STD,           // X86/X64
  INST_STMXCSR,
  INST_SUB,           // X86/X64
  INST_SUBPD,
  INST_SUBPS,
  INST_SUBSD,
  INST_SUBSS,
  INST_TEST,          // X86/X64
  INST_UCOMISD,
  INST_UCOMISS,
  INST_UD2,           // X86/X64
  INST_UNPCKHPD,
  INST_UNPCKHPS,
  INST_UNPCKLPD,
  INST_UNPCKLPS,
  INST_XADD,          // X86/X64 (i486)
  INST_XCHG,          // X86/X64 (i386)
  INST_XOR,           // X86/X64
  INST_XORPD,
  INST_XORPS,

  _INST_COUNT,

  _INST_J_BEGIN = INST_J,
  _INST_J_END = INST_JMP
};

// ============================================================================
// [AsmJit::Instruction Name]
// ============================================================================

//! @internal
//! 
//! @brief Instruction names.
ASMJIT_API extern const char instructionName[];

// ============================================================================
// [AsmJit::Instruction Description]
// ============================================================================

struct InstructionDescription
{
  // --------------------------------------------------------------------------
  // [Instruction Groups]
  // --------------------------------------------------------------------------

  //! @brief Instruction groups.
  //!
  //! This should be only used by assembler, because it's @c AsmJit::Assembler
  //! specific grouping. Each group represents one 'case' in the Assembler's 
  //! main emit method.
  enum G
  {
    // Gloup categories.
    G_EMIT,

    G_ALU,
    G_BSWAP,
    G_BT,
    G_CALL,
    G_CRC32,
    G_ENTER,
    G_IMUL,
    G_INC_DEC,
    G_J,
    G_JMP,
    G_LEA,
    G_M,
    G_MOV,
    G_MOV_PTR,
    G_MOVSX_MOVZX,
    G_MOVSXD,
    G_PUSH, // I_PUSH is implemented before I_POP
    G_POP,
    G_R_RM,
    G_RM_B,
    G_RM,
    G_RM_R,
    G_REP,
    G_RET,
    G_ROT,
    G_SHLD_SHRD,
    G_TEST,
    G_XCHG,

    // Group for x87 FP instructions in format mem or st(i), st(i) (fadd, fsub, fdiv, ...)
    G_X87_FPU,
    // Group for x87 FP instructions in format st(i), st(i)
    G_X87_STI,
    // Group for fld/fst/fstp instruction, internally uses I_X87_MEM group.
    G_X87_MEM_STI,
    // Group for x87 FP instructions that uses Word, DWord, QWord or TWord memory pointer.
    G_X87_MEM,
    // Group for x87 FSTSW/FNSTSW instructions
    G_X87_FSTSW,

    // Group for movbe instruction
    G_MOVBE,

    // Group for MMX/SSE instructions in format (X)MM|Reg|Mem <- (X)MM|Reg|Mem,
    // 0x66 prefix must be set manually in opcodes.
    // - Primary opcode is used for instructions in (X)MM <- (X)MM/Mem format,
    // - Secondary opcode is used for instructions in (X)MM/Mem <- (X)MM format.
    G_MMU_MOV,

    // Group for movd and movq instructions.
    G_MMU_MOVD,
    G_MMU_MOVQ,

    // Group for pextrd, pextrq and pextrw instructions (it's special instruction
    // not similar to others)
    G_MMU_PEXTR,

    // Group for prefetch instruction
    G_MMU_PREFETCH,

    // Group for MMX/SSE instructions in format (X)MM|Reg <- (X)MM|Reg|Mem|Imm,
    // 0x66 prefix is added for MMX instructions that used by SSE2 registers.
    // - Primary opcode is used for instructions in (X)MM|Reg <- (X)MM|Reg|Mem format,
    // - Secondary opcode is iused for instructions in (X)MM|Reg <- Imm format.
    G_MMU_RMI,
    G_MMU_RM_IMM8,

    // Group for 3dNow instructions
    G_MMU_RM_3DNOW
  };

  // --------------------------------------------------------------------------
  // [Instruction Core Flags]
  // --------------------------------------------------------------------------

  //! @brief Instruction core flags.
  enum F
  {
    //! @brief No flags.
    F_NONE = 0x00,
    //! @brief Instruction is jump, conditional jump, call or ret.
    F_JUMP = 0x01,
    //! @brief Instruction will overwrite first operand - o[0].
    F_MOV = 0x02,
    //! @brief Instruction is X87 FPU.
    F_FPU = 0x04,
    //! @brief Instruction can be prepended using LOCK prefix
    //! (usable for multithreaded applications).
    F_LOCKABLE = 0x08,

    //! @brief Instruction is special, this is for @c Compiler.
    F_SPECIAL = 0x10,
    //! @brief Instruction always performs memory access.
    //!
    //! This flag is always combined with @c F_SPECIAL and signalizes that
    //! there is implicit address which is accessed (usually EDI/RDI or ESI/EDI).
    F_SPECIAL_MEM = 0x20
  };

  // --------------------------------------------------------------------------
  // [Instruction Operand Flags]
  // --------------------------------------------------------------------------

  //! @brief Instruction operand flags.
  enum O
  {
    // X86, MM, XMM
    O_GB          = 0x0001,
    O_GW          = 0x0002,
    O_GD          = 0x0004,
    O_GQ          = 0x0008,
    O_MM          = 0x0010,
    O_XMM         = 0x0020,
    O_MEM         = 0x0040,
    O_IMM         = 0x0080,


    O_GB_MEM      = O_GB    | O_MEM,
    O_GW_MEM      = O_GW    | O_MEM,
    O_GD_MEM      = O_GD    | O_MEM,
    O_GQ_MEM      = O_GQ    | O_MEM,

    O_GQDWB       = O_GQ    | O_GD    | O_GW    | O_GB,
    O_GQDW        = O_GQ    | O_GD    | O_GW,
    O_GQD         = O_GQ    | O_GD,
    O_GWB         = O_GW    | O_GB,

    O_GQDWB_MEM   = O_GQDWB | O_MEM,
    O_GQDW_MEM    = O_GQDW  | O_MEM,
    O_GQD_MEM     = O_GQD   | O_MEM,
    O_GWB_MEM     = O_GWB   | O_MEM,

    O_MM_MEM      = O_MM    | O_MEM,
    O_XMM_MEM     = O_XMM   | O_MEM,
    O_MM_XMM      = O_MM    | O_XMM,
    O_MM_XMM_MEM  = O_MM    | O_XMM   | O_MEM,

    // X87
    O_FM_2        = O_MEM   | 0x0100,
    O_FM_4        = O_MEM   | 0x0200,
    O_FM_8        = O_MEM   | 0x0400,
    O_FM_10       = O_MEM   | 0x0800,

    O_FM_2_4      = O_FM_2  | O_FM_4,
    O_FM_2_4_8    = O_FM_2  | O_FM_4  | O_FM_8,
    O_FM_4_8      = O_FM_4  | O_FM_8,
    O_FM_4_8_10   = O_FM_4  | O_FM_8  | O_FM_10,

    // Don't emit REX prefix.
    O_NOREX       = 0x2000
  };

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  //! @brief Instruction code.
  uint16_t code;
  //! @brief Instruction name index in instructionName[] array.
  uint16_t nameIndex;
  //! @brief Instruction group, used also by @c Compiler.
  uint8_t group;
  //! @brief Instruction type flags.
  uint8_t flags;
  //! @brief First and second operand flags (some groups depends to these settings, used also by @c Compiler).
  uint16_t oflags[2];
  //! @brief If instruction has only memory operand, this is register opcode.
  uint16_t opCodeR;
  //! @brief Primary and secondary opcodes.
  uint32_t opCode[2];

  //! @brief Get the instruction name (null terminated string).
  inline const char* getName() const { return instructionName + nameIndex; }

  //! @brief Get whether the instruction is conditional or standard jump.
  inline bool isJump() const { return (flags & F_JUMP) != 0; }
  //! @brief Get whether the instruction is MOV type.
  inline bool isMov() const { return (flags & F_MOV) != 0; }
  //! @brief Get whether the instruction is X87 FPU type.
  inline bool isFPU() const { return (flags & F_FPU) != 0; }
  //! @brief Get whether the instruction can be prefixed by LOCK prefix.
  inline bool isLockable() const { return (flags & F_LOCKABLE) != 0; }

  //! @brief Get whether the instruction is special type (this is used by
  //! @c Compiler to manage additional variables or functionality).
  inline bool isSpecial() const { return (flags & F_SPECIAL) != 0; }
  //! @brief Get whether the instruction is special type and it performs
  //! memory access.
  inline bool isSpecialMem() const { return (flags & F_SPECIAL_MEM) != 0; }
};

ASMJIT_API extern const InstructionDescription instructionDescription[];

// ============================================================================
// [AsmJit::EMIT_OPTIONS]
// ============================================================================

//! @brief Emit options, mainly for internal purposes.
enum EMIT_OPTIONS
{
  //! @brief Force REX prefix to be emitted.
  //!
  //! This option should be used carefully, because there are unencodable
  //! combinations. If you want to access ah, bh, ch or dh registers then you
  //! can't emit REX prefix and it will cause an illegal instruction error.
  EMIT_OPTION_REX_PREFIX = (1 << 0),

  //! @brief Tell @c Assembler or @c Compiler to emit and validate lock prefix.
  //!
  //! If this option is used and instruction doesn't support LOCK prefix then
  //! invalid instruction error is generated.
  EMIT_OPTION_LOCK_PREFIX = (1 << 1),

  //! @brief Emit short/near jump or conditional jump instead of far one, 
  //! saving some bytes.
  EMIT_OPTION_SHORT_JUMP = (1 << 2)
};

// ============================================================================
// [AsmJit::CALL_CONV]
// ============================================================================

//! @brief Calling convention type.
//!
//! Calling convention is scheme how function arguments are passed into 
//! function and how functions returns values. In assembler programming
//! it's needed to always comply with function calling conventions, because
//! even small inconsistency can cause undefined behavior or crash.
//!
//! List of calling conventions for 32-bit x86 mode:
//! - @c CALL_CONV_CDECL - Calling convention for C runtime.
//! - @c CALL_CONV_STDCALL - Calling convention for WinAPI functions.
//! - @c CALL_CONV_MSTHISCALL - Calling convention for C++ members under 
//!      Windows (produced by MSVC and all MSVC compatible compilers).
//! - @c CALL_CONV_MSFASTCALL - Fastest calling convention that can be used
//!      by MSVC compiler.
//! - @c CALL_CONV_BORNANDFASTCALL - Borland fastcall convention.
//! - @c CALL_CONV_GCCFASTCALL_2 - GCC fastcall convention with 2 register
//!      arguments.
//! - @c CALL_CONV_GCCFASTCALL_3 - GCC fastcall convention with 3 register
//!      arguments.
//!
//! List of calling conventions for 64-bit x86 mode (x64):
//! - @c CALL_CONV_X64W - Windows 64-bit calling convention (WIN64 ABI).
//! - @c CALL_CONV_X64U - Unix 64-bit calling convention (AMD64 ABI).
//!
//! There is also @c CALL_CONV_DEFAULT that is defined to fit best to your 
//! compiler.
//!
//! These types are used together with @c AsmJit::Compiler::newFunction() 
//! method.
enum CALL_CONV
{
  //! @brief Calling convention is invalid (can't be used).
  CALL_CONV_NONE = 0,

  // [X64 Calling Conventions]

  //! @brief X64 calling convention for Windows platform (WIN64 ABI).
  //!
  //! For first four arguments are used these registers:
  //! - 1. 32/64-bit integer or floating point argument - rcx/xmm0
  //! - 2. 32/64-bit integer or floating point argument - rdx/xmm1
  //! - 3. 32/64-bit integer or floating point argument - r8/xmm2
  //! - 4. 32/64-bit integer or floating point argument - r9/xmm3
  //!
  //! Note first four arguments here means arguments at positions from 1 to 4
  //! (included). For example if second argument is not passed by register then
  //! rdx/xmm1 register is unused.
  //!
  //! All other arguments are pushed on the stack in right-to-left direction.
  //! Stack is aligned by 16 bytes. There is 32-byte shadow space on the stack
  //! that can be used to save up to four 64-bit registers (probably designed to
  //! be used to save first four arguments passed in registers).
  //!
  //! Arguments direction:
  //! - Right to Left (except for first 4 parameters that's in registers)
  //!
  //! Stack is cleaned by:
  //! - Caller.
  //!
  //! Return value:
  //! - Integer types - RAX register.
  //! - Floating points - XMM0 register.
  //!
  //! Stack is always aligned by 16 bytes.
  //!
  //! More information about this calling convention can be found on MSDN:
  //! http://msdn.microsoft.com/en-us/library/9b372w95.aspx .
  CALL_CONV_X64W = 1,

  //! @brief X64 calling convention for Unix platforms (AMD64 ABI).
  //!
  //! First six 32 or 64-bit integer arguments are passed in rdi, rsi, rdx, 
  //! rcx, r8, r9 registers. First eight floating point or XMM arguments 
  //! are passed in xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7 registers.
  //! This means that in registers can be transferred up to 14 arguments total.
  //!
  //! There is also RED ZONE below the stack pointer that can be used for 
  //! temporary storage. The red zone is the space from [rsp-128] to [rsp-8].
  //! 
  //! Arguments direction:
  //! - Right to Left (Except for arguments passed in registers).
  //!
  //! Stack is cleaned by:
  //! - Caller.
  //!
  //! Return value:
  //! - Integer types - RAX register.
  //! - Floating points - XMM0 register.
  //!
  //! Stack is always aligned by 16 bytes.
  CALL_CONV_X64U = 2,

  // [X86 Calling Conventions]

  //! @brief Cdecl calling convention (used by C runtime).
  //!
  //! Compatible across MSVC and GCC.
  //!
  //! Arguments direction:
  //! - Right to Left
  //!
  //! Stack is cleaned by:
  //! - Caller.
  CALL_CONV_CDECL = 3,

  //! @brief Stdcall calling convention (used by WinAPI).
  //!
  //! Compatible across MSVC and GCC.
  //!
  //! Arguments direction:
  //! - Right to Left
  //!
  //! Stack is cleaned by:
  //! - Callee.
  //!
  //! Return value:
  //! - Integer types - EAX:EDX registers.
  //! - Floating points - st(0) register.
  CALL_CONV_STDCALL = 4,

  //! @brief MSVC specific calling convention used by MSVC/Intel compilers
  //! for struct/class methods.
  //!
  //! This is MSVC (and Intel) only calling convention used in Windows
  //! world for C++ class methods. Implicit 'this' pointer is stored in
  //! ECX register instead of storing it on the stack.
  //!
  //! Arguments direction:
  //! - Right to Left (except this pointer in ECX)
  //!
  //! Stack is cleaned by:
  //! - Callee.
  //!
  //! Return value:
  //! - Integer types - EAX:EDX registers.
  //! - Floating points - st(0) register.
  //!
  //! C++ class methods that have variable count of arguments uses different
  //! calling convention called cdecl.
  //!
  //! @note This calling convention is always used by MSVC for class methods,
  //! it's implicit and there is no way how to override it.
  CALL_CONV_MSTHISCALL = 5,

  //! @brief MSVC specific fastcall.
  //!
  //! Two first parameters (evaluated from left-to-right) are in ECX:EDX 
  //! registers, all others on the stack in right-to-left order.
  //!
  //! Arguments direction:
  //! - Right to Left (except to first two integer arguments in ECX:EDX)
  //!
  //! Stack is cleaned by:
  //! - Callee.
  //!
  //! Return value:
  //! - Integer types - EAX:EDX registers.
  //! - Floating points - st(0) register.
  //!
  //! @note This calling convention differs to GCC one in stack cleaning
  //! mechanism.
  CALL_CONV_MSFASTCALL = 6,

  //! @brief Borland specific fastcall with 2 parameters in registers.
  //!
  //! Two first parameters (evaluated from left-to-right) are in ECX:EDX 
  //! registers, all others on the stack in left-to-right order.
  //!
  //! Arguments direction:
  //! - Left to Right (except to first two integer arguments in ECX:EDX)
  //!
  //! Stack is cleaned by:
  //! - Callee.
  //!
  //! Return value:
  //! - Integer types - EAX:EDX registers.
  //! - Floating points - st(0) register.
  //!
  //! @note Arguments on the stack are in left-to-right order that differs
  //! to other fastcall conventions used in different compilers.
  CALL_CONV_BORLANDFASTCALL = 7,

  //! @brief GCC specific fastcall with 2 parameters in registers.
  //!
  //! Two first parameters (evaluated from left-to-right) are in ECX:EDX 
  //! registers, all others on the stack in right-to-left order.
  //!
  //! Arguments direction:
  //! - Right to Left (except to first two integer arguments in ECX:EDX)
  //!
  //! Stack is cleaned by:
  //! - Caller.
  //!
  //! Return value:
  //! - Integer types - EAX:EDX registers.
  //! - Floating points - st(0) register.
  //!
  //! @note This calling convention differs to MSVC one in stack cleaning
  //! mechanism.
  CALL_CONV_GCCFASTCALL_2 = 8,

  //! @brief GCC specific fastcall with 3 parameters in registers.
  //!
  //! Three first parameters (evaluated from left-to-right) are in 
  //! ECX:EDX:EAX registers, all others on the stack in right-to-left order.
  //!
  //! Arguments direction:
  //! - Right to Left (except to first three integer arguments in ECX:EDX:EAX)
  //!
  //! Stack is cleaned by:
  //! - Caller.
  //!
  //! Return value:
  //! - Integer types - EAX:EDX registers.
  //! - Floating points - st(0) register.
  CALL_CONV_GCCFASTCALL_3 = 9,

  // [Preferred Calling Convention]

  //! @def CALL_CONV_DEFAULT
  //! @brief Default calling convention for current platform / operating 
  //! system.

#if defined(ASMJIT_X86)
  CALL_CONV_DEFAULT = CALL_CONV_CDECL
#else
# if defined(WIN32) || defined(_WIN32) || defined(WINDOWS)
  CALL_CONV_DEFAULT = CALL_CONV_X64W
# else
  CALL_CONV_DEFAULT = CALL_CONV_X64U
# endif
#endif // ASMJIT_X86
};

// ============================================================================
// [AsmJit::VARIABLE_TYPE]
// ============================================================================

//! @brief Variable type.
enum VARIABLE_TYPE
{
  // --------------------------------------------------------------------------
  // [Platform Dependent]
  // --------------------------------------------------------------------------

  //! @brief Variable is 32-bit general purpose register.
  VARIABLE_TYPE_GPD = 0,
  //! @brief Variable is 64-bit general purpose register.
  VARIABLE_TYPE_GPQ = 1,

  //! @var VARIABLE_TYPE_GPN
  //! @brief Variable is system wide general purpose register (32-bit or 64-bit).
#if defined(ASMJIT_X86)
  VARIABLE_TYPE_GPN = VARIABLE_TYPE_GPD,
#else
  VARIABLE_TYPE_GPN = VARIABLE_TYPE_GPQ,
#endif

  //! @brief Variable is X87 (FPU).
  VARIABLE_TYPE_X87 = 2,

  //! @brief Variable is X87 (FPU) SP-FP number (float).
  VARIABLE_TYPE_X87_1F = 3,

  //! @brief Variable is X87 (FPU) DP-FP number (double).
  VARIABLE_TYPE_X87_1D = 4,

  //! @brief Variable is MM register / memory location.
  VARIABLE_TYPE_MM = 5,

  //! @brief Variable is XMM register / memory location.
  VARIABLE_TYPE_XMM = 6,

  //! @brief Variable is SSE scalar SP-FP number.
  VARIABLE_TYPE_XMM_1F = 7,
  //! @brief Variable is SSE packed SP-FP number (4 floats).
  VARIABLE_TYPE_XMM_4F = 8,

  //! @brief Variable is SSE2 scalar DP-FP number.
  VARIABLE_TYPE_XMM_1D = 9,
  //! @brief Variable is SSE2 packed DP-FP number (2 doubles).
  VARIABLE_TYPE_XMM_2D = 10,

  //! @brief Count of variable types.
  _VARIABLE_TYPE_COUNT = 11,

  // --------------------------------------------------------------------------
  // [Platform Independent]
  // --------------------------------------------------------------------------

  //! @brief Variable is 32-bit integer.
  VARIABLE_TYPE_INT32 = VARIABLE_TYPE_GPD,
  //! @brief Variable is 64-bit integer.
  VARIABLE_TYPE_INT64 = VARIABLE_TYPE_GPQ,
  //! @brief Variable is system dependent integer / pointer.
  VARIABLE_TYPE_INTPTR = VARIABLE_TYPE_GPN,

#if !defined(ASMJIT_NODOC)
#if defined(ASMJIT_X86)
  VARIABLE_TYPE_FLOAT = VARIABLE_TYPE_X87_1F,
  VARIABLE_TYPE_DOUBLE = VARIABLE_TYPE_X87_1D
#else
  VARIABLE_TYPE_FLOAT = VARIABLE_TYPE_XMM_1F,
  VARIABLE_TYPE_DOUBLE = VARIABLE_TYPE_XMM_1D
#endif
#else
  //! @brief Variable is SP-FP (x87 or xmm).
  VARIABLE_TYPE_FLOAT = XXX,
  //! @brief Variable is DP-FP (x87 or xmm).
  VARIABLE_TYPE_DOUBLE = XXX
#endif
};

// ============================================================================
// [AsmJit::VARIABLE_HINT]
// ============================================================================

//! @brief Variable hint (used by @ref Compiler).
//!
//! @sa @ref Compiler.
enum VARIABLE_HINT
{
  //! @brief Alloc variable.
  VARIABLE_HINT_ALLOC = 0,
  //! @brief Spill variable.
  VARIABLE_HINT_SPILL = 1,
  //! @brief Save variable if modified.
  VARIABLE_HINT_SAVE = 2,
  //! @brief Save variable if modified and mark it as unused.
  VARIABLE_HINT_SAVE_AND_UNUSE = 3,
  //! @brief Mark variable as unused.
  VARIABLE_HINT_UNUSE = 4
};

//! @}

} // AsmJit namespace

// [Api-End]
#include "ApiEnd.h"

// [Guard]
#endif // _ASMJIT_DEFSX86X64_H
