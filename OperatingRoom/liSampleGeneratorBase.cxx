//--------------------------------------------
//
//    Project Registrator
//
//    Author:  Luis Ibanez
//  
//    Directed by: Elizabeth Bullitt, MD
//
//
//     Division of Neurosugery
//     Department of Surgery
//     University of North Carolina
//     Chapel Hill, NC 27514
//
//--------------------------------------------


#include <liSampleGeneratorBase.h>



//----------------------------------------------
//
//    Constructor
//
//----------------------------------------------
liSampleGeneratorBase::liSampleGeneratorBase() 
{
  m_PointSet  = PointSetType::New();
}


//----------------------------------------------
//
//    Destructor
//
//----------------------------------------------
liSampleGeneratorBase::~liSampleGeneratorBase() 
{
  
}




//----------------------------------------------
//
//    Generate Samples
//
//----------------------------------------------
void liSampleGeneratorBase::GenerateSamples( SamplesType & samples ) 
{
  
}





//----------------------------------------------
//
//    Return the mesh with samples
//
//----------------------------------------------
liSampleGeneratorBase::PointSetType::Pointer
liSampleGeneratorBase::GetPointSet( void )
{
  return m_PointSet;
}



//----------------------------------------------
//
//    Transfer the samples to the mesh
//
//----------------------------------------------
void
liSampleGeneratorBase::TransferSamplesToPointSet( const SamplesType & samples )
{
  
  PointSetType::PointsContainer::Pointer     
                  points = PointSetType::PointsContainer::New();

  PointSetType::PointDataContainer::Pointer  
                  values = PointSetType::PointDataContainer::New();

  points->Reserve( samples.size() );
  values->Reserve( samples.size() );
  
  PointSetType::PointsContainer::Iterator      pi = points->Begin();
  PointSetType::PointDataContainer::Iterator   vi = values->Begin();

  SamplesType::const_iterator it = samples.begin();
  while( it != samples.end() )
  {
    pi.Value() = it->point;
    vi.Value() = it->value;
    ++it;
    ++pi;
    ++vi;
  }

  m_PointSet->SetPoints( points );
  m_PointSet->SetPointData( values );


}






//----------------------------------------------
//
//  Normalize the values among each sample set
//
//----------------------------------------------
void 
liSampleGeneratorBase::NormalizeSetOfSamples( SamplesType & samples )
{
  
    
  double sum  = 0.0;
  double sum2 = 0.0;

  SamplesType::iterator is = samples.begin();
  while( is != samples.end() )
  {
    const double value = is->value;
    sum  += value;
    sum2 += value * value;
    is++;
  }

  const unsigned long n = samples.size();
  const double mean = sum / n;
  const double meanDeviation = sqrt( sum2/n - mean*mean );

  is = samples.begin();
  while( is != samples.end() )
  {
   is->value = (is->value - mean) / meanDeviation;
   is++;
  }


}





