#ifndef KDBUS_COMPAT_3_10_H
#define KDBUS_COMPAT_3_10_H

#include <linux/kernel.h>
#include <linux/err.h>

/* connection.c */
#define U8_MAX		((uint8_t)(~0U))
#define U16_MAX		((uint16_t)(~0U))
#define U32_MAX		((uint32_t)(~0U))

/* fs.c */
typedef int (*filldir_t)(void *, const char *, int, loff_t, u64, unsigned);
struct dir_context {
        const filldir_t actor;
        loff_t pos;
};

static inline bool dir_emit(struct dir_context *ctx,
                            const char *name, int namelen,
                            u64 ino, unsigned type)
{
	BUG();
	return 0;
}

static inline bool dir_emit_dots(struct file *file, struct dir_context *ctx)
{ 
	BUG();
	return 0;
}


static void truncate_inode_pages_final(struct address_space *p)
{
	truncate_inode_pages(p, 0);
}

/* handle.c */
static inline int __must_check PTR_ERR_OR_ZERO(__force const void *ptr)
{
        if (IS_ERR(ptr))
                return PTR_ERR(ptr);
        else
                return 0;
}

/* metadata.c */
#define KDBUS_COMPAT_FEATURE_DISABLE 0

#endif /* KDBUS_COMPAT_3_10_H */
