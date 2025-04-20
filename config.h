/* config.h - libf config definitions */
#ifndef LIBF_CONFIG_H
#define LIBF_CONFIG_H


/* extern symbol */
#undef FSYMBOL
#define FSYMBOL(name) libf_##name
/* standard extern symbol */
#undef XSYMBOL
#define XSYMBOL(name) x##name

/* machine 32bit */
#undef LIBF_MARCH_BIT_32
#define LIBF_MARCH_BIT_32 32
/* machine 64bit */
#undef LIBF_MARCH_BIT_64
#define LIBF_MARCH_BIT_64 64

/* machine architecture 32bit/64bit */
#undef LIBF_MARCH_BIT
#ifdef __SIZEOF_POINTER__
#	if (__SIZEOF_POINTER__ == 4)
#		define LIBF_MARCH_BIT LIBF_MARCH_BIT_32
#	else
#		define LIBF_MARCH_BIT LIBF_MARCH_BIT_64
#	endif
#else
#	error "!!!undefined __SIZEOF_POINTER__!!!"
#endif


#endif
