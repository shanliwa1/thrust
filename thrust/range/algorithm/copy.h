/*
 *  Copyright 2008-2010 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <thrust/detail/config.h>
#include <thrust/range/algorithm/detail/copy_result.h>

namespace thrust
{

namespace experimental
{

namespace range
{


template<typename SinglePassRange1, typename SinglePassRange2>
  inline typename detail::copy_result<SinglePassRange2>::type
    copy(const SinglePassRange1 &input,
         SinglePassRange2       &result);


// add a second overload to accept temporary ranges for the second parameter from things like zip()
//
// XXX change
//
//     const SinglePassRange2 &result
//
//     to
//
//     SinglePassRange2 &&result
//
//     upon addition of rvalue references
template<typename SinglePassRange1, typename SinglePassRange2>
  inline typename detail::copy_result<const SinglePassRange2>::type
    copy(const SinglePassRange1 &input,
         const SinglePassRange2 &result);


template<typename SinglePassRange1, typename SinglePassRange2, typename Predicate>
  inline typename detail::copy_result<SinglePassRange2>::type
    copy_if(const SinglePassRange1 &input,
            SinglePassRange2 &result,
            Predicate pred);


// add a second overload to accept temporary ranges for the second parameter from things like zip()
//
// XXX change
//
//     const SinglePassRange2 &result
//
//     to
//
//     SinglePassRange2 &&result
//
//     upon addition of rvalue references
template<typename SinglePassRange1, typename SinglePassRange2, typename Predicate>
  inline typename detail::copy_result<const SinglePassRange2>::type
    copy_if(const SinglePassRange1 &input,
            const SinglePassRange2 &result,
            Predicate pred);


template<typename SinglePassRange1, typename SinglePassRange2, typename SinglePassRange3, typename Predicate>
  inline typename detail::copy_result<SinglePassRange3>::type
    copy_if(const SinglePassRange1 &input,
            const SinglePassRange2 &stencil,
            SinglePassRange3 &result,
            Predicate pred);

// add a second overload to accept temporary ranges for the third parameter from things like zip()
//
// XXX change
//
//     const SinglePassRange3 &result
//
//     to
//
//     SinglePassRange3 &&result
//
//     upon addition of rvalue references
template<typename SinglePassRange1, typename SinglePassRange2, typename SinglePassRange3, typename Predicate>
  inline typename detail::copy_result<const SinglePassRange3>::type
    copy_if(const SinglePassRange1 &input,
            const SinglePassRange2 &stencil,
            const SinglePassRange3 &result,
            Predicate pred);


} // end range

} // end experimental

} // end thrust

#include <thrust/range/algorithm/detail/copy.inl>
