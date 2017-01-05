/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license MPL v2.0 (see license file)
 */
#include <eproperty/details/Range.hxx>
#include <etk/types.hpp>
#include <etk/math/Vector2D.hpp>
#include <etk/math/Vector3D.hpp>
#include <etk/Color.hpp>

// void generic properties
template class eproperty::Range<int64_t>;
template class eproperty::Range<int32_t>;
template class eproperty::Range<int16_t>;
template class eproperty::Range<int8_t>;

template class eproperty::Range<uint64_t>;
template class eproperty::Range<uint32_t>;
template class eproperty::Range<uint16_t>;
template class eproperty::Range<uint8_t>;

template class eproperty::Range<float>;
template class eproperty::Range<double>;

// etk generic vetor 2D
template class eproperty::Range<vec2>;
template class eproperty::Range<bvec2>;
template class eproperty::Range<ivec2>;
template class eproperty::Range<uivec2>;
// etk generic vetor 3D
template class eproperty::Range<vec3>;
template class eproperty::Range<bvec3>;
template class eproperty::Range<ivec3>;
template class eproperty::Range<uivec3>;
// etk generic color
/*
template class eproperty::Range<etk::Color<unsigned char,4>>;
template class eproperty::Range<etk::Color<unsigned char,3>>;
template class eproperty::Range<etk::Color<float,4>>;
template class eproperty::Range<etk::Color<float,3>>;
*/
