#ifndef TEXPACKR_TYPES_H_
#define TEXPACKR_TYPES_H_

/// vector2
/// no need to be float, integer type is enough for us
typedef struct
{
	int x;
	int y;
} texpackr_vec2;

/// sprite struct
/// important attribute is offset, and size
typedef struct
{
	/// dynamically allocate as exact number of bytes need to hold
	/// path string
	char* filename;

	/// offset of sprite in the atlas
	texpackr_vec2 offset;
	/// size of sprite in the atlas
	texpackr_vec2 size;
	/// image data
	/// availability depends on whether query with which function
	/// it can contain NULL, or actual image data.
	/// This is due to keeping memory usage as low as possible.
	void* image_data;

} texpackr_sprite;

struct texpackr_node;

/// sheet as top level to hold other information
typedef struct 
{
	/// list of sprites in the sheet
	texpackr_sprite* sprites;

	/// number of sprite in the sheet
	int sprite_count;

	/// (internally used)
	/// managed sprite count, available mem space for adding more sprites
	int msprite_count;

	/// resolution or image size of the sheet
	texpackr_vec2 size;

	/// (internally used)
	struct texpackr_node* node;

	/// (internally used)
	/// opaque pointer, behind the scene it works with libpng's png_bytepp
	///
	/// sheet maintains this during creation phase
	/// to reduce memory usage and a need to hold each sprite's image data.
	/// Each sprite's image data will be put into this attribute each time
	/// it's inserted.
	///
	/// pixel format is RGBA 8-bit per channel.
	void* pixels;

} texpackr_sheet;

#endif
