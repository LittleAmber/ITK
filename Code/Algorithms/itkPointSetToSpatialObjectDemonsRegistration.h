/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkPointSetToSpatialObjectDemonsRegistration.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkPointSetToSpatialObjectDemonsRegistration_h
#define __itkPointSetToSpatialObjectDemonsRegistration_h

#include "itkProcessObject.h"
#include "itkImage.h"
#include "itkPointSetToImageMetric.h"
#include "itkSingleValuedNonLinearOptimizer.h"

namespace itk
{

/** \class PointSetToSpatialObjectDemonsRegistration
 * \brief Implementation of Demons Registration between a PointSet and a SpatialObject
 *
 * The simplest case of Demons registration suggested by P. Thirion in his
 * paper[1] is defined by a Model and Scene. The Model should be able to
 * respond to the queries of whether a point is inside or outside of the object
 * of interest, while the Scene provides a number of points (the Demons) with
 * vector indicating the direction of inside-outside of the equivalent object
 * of interest. In this implementation, the Scene is represented by an
 * itk::PointSet that has Vectors as PixelData. These vectors should be
 * provided by the user of this class and must be pointing outside of the
 * object of interest. The Model is naturally represented by a
 * itk::SpatialObject since its interface responds to the IsInside() method.
 *
 * This class is intended to be derived in order to define the method that will
 * update the transform. Such method will be specific for the particular type of 
 * transform used.
 *
 * [1] J-P. Thirion "Image matching as a Diffusion Process: and Analogy with
 * Maxwell's Demons", Medical Image Analysis, 1998, Vol. 2, No. 3, pp 243-260.
 *
 * \ingroup RegistrationFilters
 */
template <typename TFixedPointSet, typename TMovingSpatialObject>
class ITK_EXPORT PointSetToSpatialObjectDemonsRegistration : public ProcessObject 
{
public:
  /** Standard class typedefs. */
  typedef PointSetToSpatialObjectDemonsRegistration  Self;
  typedef ProcessObject                              Superclass;
  typedef SmartPointer<Self>                         Pointer;
  typedef SmartPointer<const Self>                   ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
  /** Run-time type information (and related methods). */
  itkTypeMacro(PointSetToSpatialObjectDemonsRegistration, ProcessObject);

  /**  Type of the Fixed PointSet. */
  typedef          TFixedPointSet                   FixedPointSetType;
  typedef typename FixedPointSetType::ConstPointer  FixedPointSetConstPointer;

  /**  Type of the Moving image. */
  typedef          TMovingSpatialObject             MovingSpatialObjectType;
  typedef typename MovingSpatialObjectType::ConstPointer    MovingSpatialObjectConstPointer;

  /** Method that initiates the registration. */
  void StartRegistration(void);

  /** Set/Get the Fixed image. */
  itkSetConstObjectMacro( FixedPointSet, FixedPointSetType );
  itkGetConstObjectMacro( FixedPointSet, FixedPointSetType ); 

  /** Set/Get the Moving image. */
  itkSetConstObjectMacro( MovingSpatialObject, MovingSpatialObjectType );
  itkGetConstObjectMacro( MovingSpatialObject, MovingSpatialObjectType );

protected:
  PointSetToSpatialObjectDemonsRegistration();
  virtual ~PointSetToSpatialObjectDemonsRegistration() {};
  void PrintSelf(std::ostream& os, Indent indent) const;

private:
  PointSetToSpatialObjectDemonsRegistration(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
  
  MovingSpatialObjectConstPointer  m_MovingSpatialObject;
  FixedPointSetConstPointer        m_FixedPointSet;

  
};


} // end namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkPointSetToSpatialObjectDemonsRegistration.txx"
#endif

#endif