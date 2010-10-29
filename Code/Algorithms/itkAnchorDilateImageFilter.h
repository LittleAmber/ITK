/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkAnchorDilateImageFilter_h
#define __itkAnchorDilateImageFilter_h

#include "itkAnchorErodeDilateImageFilter.h"

namespace itk
{
template< class TImage, class TKernel >
class ITK_EXPORT AnchorDilateImageFilter:
  public AnchorErodeDilateImageFilter< TImage, TKernel, std::greater< typename TImage::PixelType >,
                                       std::greater_equal< typename TImage::PixelType > >

{
public:
  typedef AnchorDilateImageFilter
                                                                                           Self;
  typedef AnchorErodeDilateImageFilter< TImage, TKernel, std::less< typename TImage::PixelType >,
                                        std::greater_equal< typename TImage::PixelType > > Superclass;

  /** Runtime information support. */
  itkTypeMacro(AnchorDilateImageFilter,
               AnchorErodeDilateImageFilter);

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  virtual ~AnchorDilateImageFilter() {}
protected:

  typedef typename TImage::PixelType PixelType;

  AnchorDilateImageFilter()
  {
    this->m_Boundary = NumericTraits< PixelType >::NonpositiveMin();
  }

  void PrintSelf(std::ostream & os, Indent indent) const
  {
    os << indent << "Anchor dilation: " << std::endl;
  }

private:

  AnchorDilateImageFilter(const Self &); //purposely not implemented
  void operator=(const Self &);          //purposely not implemented
};
} // namespace itk

#endif