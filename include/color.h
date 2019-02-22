#ifndef _COLOR_H_
#define _COLOR_H_

	/**
	 * Type of a color channel
	 */
	typedef unsigned int color_t;

	/**
	 * @brief      Identifies each color channel. 
	 */
	enum channel_e : color_t {
		r = 0, //<! Red
		g = 1, //<! Green
		b = 2, //<! Blue
	};

	class Color {

		public:
			/**
			 * The 3 channels: red, green and blue
			 */
			color_t channels [3];

			/**
			 * @brief      Constructs the object.
			 *
			 * @param[in]  r     The red value
			 * @param[in]  g     The green value
			 * @param[in]  b     The blue value
			 */
			Color( color_t r = 0, color_t g = 0, color_t b = 0);

			/**
			 * @brief      Constructs the object.
			 *
			 * @param[in]  clone  The clone
			 */
			Color (const Color &clone);

			/**
			 * @brief      Destroys the object.
			 */
			~Color();

			/**
			 * @brief      Assignment operator
			 *
			 * @param[in]  rhs   The right hand side
			 *
			 * @return     A new color equals rhs
			 */
			Color& operator= (const Color & rhs);

			/**
			 * @brief      Comparison operator
			 *
			 * @param[in]  rhs   The right hand side
			 *
			 * @return     True, if equals; false otherwise
			 */
			bool operator== (const Color & rhs);
	
	
			color_t * get_color_value ();
	};

#endif