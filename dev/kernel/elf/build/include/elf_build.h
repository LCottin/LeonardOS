#ifndef __ELF_BUILD_H__
#define __ELF_BUILD_H__

#include "types_usr.h"

#define K_ELF_IDENT_SIZE     16                    /* ELF identification size */

/**********************************************************************
 * @brief ELF header structure for 64-bit ELF files.
 *
 * This structure represents the header of a 64-bit ELF file, containing
 * metadata about the file such as its type, entry point, and offsets to
 * segment and section headers.
 **********************************************************************/
typedef struct __attribute__((packed))
{
    uint8_t  ident[K_ELF_IDENT_SIZE]; /* ELF identification */
    uint16_t type;                    /* Object file type */
    uint16_t machine;                 /* Machine type */
    uint32_t version;                 /* Object file version */
    addr_t   entry_point;             /* Entry point address */
    addr_t   segm_hdr_off;            /* Segment header offset */
    addr_t   sect_hdr_off;            /* Section header offset */
    uint32_t flags;                   /* Processor-specific flags */
    uint16_t elhdr_size;              /* ELF header size */
    uint16_t segm_hdr_ent_size;       /* Size of a segment header entry */
    uint16_t segm_hdr_nb_entry;       /* Number of segment header entries */
    uint16_t sect_hdr_ent_size;       /* Size of a section header entry */
    uint16_t sect_hdr_nb_entry;       /* Number of section header entries */
    uint16_t sect_str_idx;            /* Section name string table index */
} ELF64_elf_hdr_t;


/**********************************************************************
 * @brief Segment header structure for 64-bit ELF files.
 *
 * This structure represents a segment header in a 64-bit ELF file, containing
 * information about a segment to be loaded into memory, such as its type,
 * virtual address, and size.
 **********************************************************************/
typedef struct __attribute__((packed))
{
    uint32_t type;          /* Segment type */
    uint32_t flags;         /* Segment flags */
    addr_t   offset;        /* Offset in file */
    addr_t   virt_addr;     /* Virtual address in memory */
    addr_t   phy_addr;      /* Reserved (physical address) */
    uint64_t file_size;     /* Size of segment in file */
    uint64_t mem_size;      /* Size of segment in memory */
    uint64_t align;         /* Alignment */
} ELF64_segment_hdr_t;


#endif /* __ELF_BUILD_H__ */
