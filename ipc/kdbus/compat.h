#ifndef KDBUS_COMPAT_3_10_H
#define KDBUS_COMPAT_3_10_H

#include <linux/kernel.h>
#include <linux/err.h>

/* connection.c */
#define U16_MAX 65535
#define U8_MAX 255
#define U32_MAX UINT_MAX

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
	BUG();
}

/* handle.c */
static inline int __must_check PTR_ERR_OR_ZERO(__force const void *ptr)
{
        if (IS_ERR(ptr))
                return PTR_ERR(ptr);
        else
                return 0;
}


#endif /* KDBUS_COMPAT_3_10_H */
