/** @file
 * @author Edouard DUPIN
 * 
 * @copyright 2016, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */
#include <eproperty/details/Value.hxx>

#include <etk/types.hpp>
#include <etk/math/Vector2D.hpp>
#include <etk/math/Vector3D.hpp>
#include <etk/Color.hpp>

// void generic properties
template class eproperty::Value<bool>;
template class eproperty::Value<std::string>;
#if __CPP_VERSION__ >= 2011
	template class eproperty::Value<std::u32string>;
#endif
template class eproperty::Value<int64_t>;
template class eproperty::Value<int32_t>;
template class eproperty::Value<int16_t>;
template class eproperty::Value<int8_t>;

template class eproperty::Value<uint64_t>;
template class eproperty::Value<uint32_t>;
template class eproperty::Value<uint16_t>;
template class eproperty::Value<uint8_t>;

template class eproperty::Value<float>;
template class eproperty::Value<double>;

// etk generic vetor 2D
template class eproperty::Value<vec2>;
template class eproperty::Value<bvec2>;
template class eproperty::Value<ivec2>;
template class eproperty::Value<uivec2>;
// etk generic vetor 3D
template class eproperty::Value<vec3>;
template class eproperty::Value<bvec3>;
template class eproperty::Value<ivec3>;
template class eproperty::Value<uivec3>;
// etk generic color
template class eproperty::Value<etk::Color<unsigned char,4>>;
template class eproperty::Value<etk::Color<unsigned char,3>>;
template class eproperty::Value<etk::Color<float,4>>;
template class eproperty::Value<etk::Color<float,3>>;
