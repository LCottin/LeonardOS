#ifndef __ELF_CHECK_PRV_H__
#define __ELF_CHECK_PRV_H__

#define K_ELF_IDENT_CLASS_OFF       4U       /* ELF Class */
#define K_ELF_IDENT_DATA_OFF        5U       /* Data Encoding */
#define K_ELF_IDENT_VERSION_OFF     6U       /* ELF Version */
#define K_ELF_IDENT_OSABI_OFF       7U       /* OS/ABI */
#define K_ELF_IDENT_ABIVERSION_OFF  8U       /* ABI Version */

#define K_ELF_IDENT_CLASS_VAL       2U       /* 64-bit ELF */
#define K_ELF_IDENT_DATA_VAL        1U       /* Little-endian */
#define K_ELF_IDENT_VERSION_VAL     1U       /* Current ELF version */
#define K_ELF_IDENT_OSABI_VAL       0U       /* System V ABI */
#define K_ELF_IDENT_ABIVERSION_VAL  0U       /* ABI Version */

#define K_ELF_MACHINE_AARCH64 183U           /* ARM64 */
#define K_ELF_TYPE_EXEC         2U           /* Executable file */

#endif /* __ELF_CHECK_PRV_H__ */
