#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gif_result_t {
	int delay;
	unsigned char *data;
	struct gif_result_t *next;
} gif_result;

STBIDEF int stbi_is_animated_gif( char const * filename ) {

	FILE *f;
	stbi__context s;
	int result = 0;

    memset( &s, 0, sizeof(stbi__context) );

	if (!(f = stbi__fopen(filename, "rb")))
		return 0;

	stbi__start_file(&s, f);

	if (stbi__gif_test(&s)) {

		int c;
		stbi__gif g;
        unsigned char *ignored;
        
        memset( &g, 0, sizeof(stbi__gif) );

        int frames = 0;
        int maxDelay = 0;
		while (stbi__gif_load_next(&s, &g, &c, 4, ignored))
		{
            if ( g.delay > 0 ) {
                maxDelay = g.delay;
            }
            ++frames;
		}

        if ( ( frames > 1 ) && ( maxDelay > 0 ) ) {
            result = 1;
        } else {
            result = 0;
        }
    }

    fclose(f);
	return result;

}

STBIDEF unsigned char *stbi_xload(char const *filename, int *x, int *y, int *frames)
{
	FILE *f;
	stbi__context s;
	unsigned char *result = 0;

    memset( &s, 0, sizeof(stbi__context) );

	if (!(f = stbi__fopen(filename, "rb")))
		return stbi__errpuc("can't fopen", "Unable to open file");

	stbi__start_file(&s, f);

	if (stbi__gif_test(&s))
	{
		int c;
		stbi__gif g;
		gif_result head;
		gif_result *prev = 0, *gr = &head;
        unsigned char *ignored;

		memset(&g, 0, sizeof(g));
		memset(&head, 0, sizeof(head));

		*frames = 0;
        
		while (gr->data = stbi__gif_load_next(&s, &g, &c, 4, ignored))
		{
            
			if (gr->data == (unsigned char*)&s)
			{
				gr->data = 0;
				break;
			}

            unsigned char * ptr = gr->data;

            if ( ptr ) {
                gr->data = malloc( g.w * g.h * 4 );

                memset( gr->data, 0, g.w * g.h * 4 );

                memcpy( gr->data, ptr, g.w * g.h * 4 );
            }

			if (prev) prev->next = gr;
			gr->delay = g.delay;
			prev = gr;
			gr = (gif_result*) stbi__malloc(sizeof(gif_result));
			memset(gr, 0, sizeof(gif_result));
			++(*frames);
		}

		// STBI_FREE(g.out);

		// if (gr != &head) 
		// 	STBI_FREE(gr);

		if (*frames > 0)
		{
			*x = g.w;
			*y = g.h;
		}

		result = head.data;

		if (*frames > 1)
		{
			unsigned int size = 4 * g.w * g.h;
			unsigned char *p = 0;

			result = (unsigned char*)stbi__malloc(*frames * (size + 2));
			gr = &head;
			p = result;

			while (gr)
			{
				prev = gr;
				memcpy(p, gr->data, size);
				p += size;
				*p++ = gr->delay & 0xFF;
				*p++ = (gr->delay & 0xFF00) >> 8;
				gr = gr->next;

				// STBI_FREE(prev->data);
				if (prev != &head) STBI_FREE(prev);
			}
		}
	}
	else
	{
		result = NULL;
	}

	fclose(f);
	return result;
}

#ifdef __cplusplus
}
#endif