#include "metadata_usr.h"

__attribute__((section(".metadata"), used))
static const metadata_t g_metadata =
{
    .header =
    {
        .magic   = K_METADATA_MAGIC,
        .type    = METADATA_TYPE_KERN,
        .version = 1U,
        .size    = sizeof(metadata_t),
    },
    .bin_name = "core",
    .flags    = 0,
};
