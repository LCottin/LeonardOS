#include "metadata_usr.h"

/* __attribute__((section(".metadata"), used)) */
__attribute__((used))
static const metadata_t g_boot_metadata =
{
    .header =
    {
        .magic   = K_METADATA_MAGIC,
        .type    = METADATA_TYPE_BOOT,
        .version = 1U,
        .size    = sizeof(metadata_t),
    },
    .bin_name = "boot",
    .flags    = 0,
};
