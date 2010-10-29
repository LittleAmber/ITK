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
#ifndef __itkMaskedRankImageFilter_txx
#define __itkMaskedRankImageFilter_txx

#include "itkMaskedRankImageFilter.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "itkOffset.h"
#include "itkProgressReporter.h"
#include "itkNumericTraits.h"

#include "itkImageRegionIterator.h"
#include "itkImageLinearConstIteratorWithIndex.h"

#include <iomanip>
#include <sstream>

namespace itk
{
template< class TInputImage, class TMaskImage, class TOutputImage, class TKernel >
MaskedRankImageFilter< TInputImage, TMaskImage, TOutputImage, TKernel >
::MaskedRankImageFilter()
{
  m_Rank = 0.5;
}

template< class TInputImage, class TMaskImage, class TOutputImage, class TKernel >
typename MaskedRankImageFilter< TInputImage, TMaskImage, TOutputImage, TKernel >::HistogramType *
MaskedRankImageFilter< TInputImage, TMaskImage, TOutputImage, TKernel >
::NewHistogram()
{
  HistogramType *hist;

  if ( UseVectorBasedHistogram() )
    {
    hist = new VHistogram();
    }
  else
    {
    hist = new MHistogram();
    }
  hist->SetRank( this->GetRank() );
  return hist;
}

template< class TInputImage, class TMaskImage, class TOutputImage, class TKernel >
void
MaskedRankImageFilter< TInputImage, TMaskImage, TOutputImage, TKernel >
::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);

  os << indent << "Rank: " << static_cast< typename NumericTraits< float >::PrintType >( m_Rank ) << std::endl;
}
} // end namespace itk
#endif