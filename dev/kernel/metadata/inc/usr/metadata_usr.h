#ifndef __METADATA_USR_H__
#define __METADATA_USR_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Magic numbers identifying metadata section.
 **********************************************************************/
#define K_METADATA_MAGIC            0x415441444154454DULL   /* "METADATA" in ascii little-endian */
#define K_METADATA_MAX_NAME_LENGTH  0x20U


/**********************************************************************
 * @brief Metadata for binary type.
 **********************************************************************/
typedef enum
{
    METADATA_TYPE_BOOT,
    METADATA_TYPE_KERN,
    METADATA_TYPE_APP,
    METADATA_TYPE_UNKNOWN
} metadata_binary_type_t;


/**********************************************************************
 * @brief Metadata header.
 **********************************************************************/
typedef struct
{
    uint64_t                magic;          /* Magic number of section, shall be first in structure */
    metadata_binary_type_t  type;           /* Binary type */
    uint32_t                version;        /* Binary version */
    size_t                  size;           /* Size of whole metadata */
    byte_t                  reserved[4];    /* Reserved for future use */
} metadata_header_t;


/**********************************************************************
 * @brief Metadata structure.
 **********************************************************************/
typedef struct
{
    metadata_header_t   header;
    char_t              bin_name[K_METADATA_MAX_NAME_LENGTH];
    uint32_t            flags;
    byte_t              reserved[4];
} metadata_t;


#endif /* __METADATA_USR_H__ */
