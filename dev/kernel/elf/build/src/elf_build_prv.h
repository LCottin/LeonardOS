#ifndef __ELF_BUILD_PRV_H__
#define __ELF_BUILD_PRV_H__

/**
 * @brief Magic numbers for 64-bit ELF files.
 */
typedef enum
{
    ELF_FILE_BOOT_MAGIC    = 0x544F4F42U, /* "BOOT" */
    ELF_FILE_KERNEL_MAGIC  = 0x4E52454BU, /* "KERN" */
    ELF_FILE_USER_MAGIC    = 0x52455355U, /* "USER" */
} ELF64_file_magic_t;

/**
 * @brief Metadata tags for ELF segments.
 */
typedef enum
{
    K_ELF_METADATA_STACK_TOP   = 1, /* Stack start address */
    K_ELF_METADATA_STACK_SIZE  = 2, /* Stack stop address */
    K_ELF_METADATA_HEAP_START  = 3, /* Heap start address */
    K_ELF_METADATA_HEAP_SIZE   = 4, /* Heap stop address */
    K_ELF_METADATA_NB_ENTRIES
} ELF64_metadata_tag_t;

/**
 * @brief Metadata structure for 64-bit ELF files.
 *
 * This structure represents a metadata entry in a 64-bit ELF file, containing
 * a tag and data pair.
 */
typedef struct
{
    ELF64_metadata_tag_t tag;   /* Metadata tag */
    uint32_t            data;   /* Metadata data */
} ELF64_metadata_t;

#endif /* __ELF_BUILD_PRV_H__ */
