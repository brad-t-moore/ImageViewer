//--------------------------------------------
//
//     Project: Operating Room
//
//     Author:  Luis Ibanez
//
//     Division of Neurosugery
//     Department of Surgery
//     University of North Carolina
//     Chapel Hill, NC 27599
//
//--------------------------------------------



#include <liShape3D.h>


namespace li {

//--------------------------------------------------
//
//    Constructor      
//
//--------------------------------------------------
Shape3D::Shape3D() 
{
  m_DrawingMode = triangles;
  m_CompileMode  = noCompile;
  m_DisplayList = 0;
  m_Color.Set( 1.0f, 1.0f, 1.0f );
  m_Transparency = 0.0f;
  m_ScheduledToRemoveDisplayList = false;
  m_ScheduledToUpdateDisplayList = false;
  m_Father = 0;
  m_AutoSensing = true;
  m_RestoreTransform = false;
}




//--------------------------------------------------
//
//    Destructor
//
//--------------------------------------------------
Shape3D::~Shape3D() 
{

  if( m_Father ) 
  {
    m_Father->RemoveComponent( this );
  }

  ContainerType::iterator it = m_Components.begin();
  while( it != m_Components.end() )
  {
    (*it)->m_Father = 0;
    ++it;
  }
  m_Components.clear();

  // The only secure way to destroy the 
  // display list (if one exists) is to
  // schedule its removal and force a 
  // last and slow redraw
  // ... before calling the destructor
  RemoveDisplayList();

}


//--------------------------------------------------
//
//    Schedule the shape to update the display list
//    during the next redraw
//
//--------------------------------------------------
void Shape3D::ScheduleToUpdateDisplayList( void )
{
  m_ScheduledToUpdateDisplayList = true;
  if( m_Father )
  {
    m_Father->ScheduleToUpdateDisplayList();
  }
}




//--------------------------------------------------
//
//    Choose drawing mode
//
//--------------------------------------------------
void Shape3D::SetDrawingMode(enum drawingModes newmode) 
{
  m_DrawingMode = newmode;

  ContainerType::iterator it = m_Components.begin();
  while( it != m_Components.end() )
  {
    (*it)->SetDrawingMode( newmode );
    ++it;
  }

  if( m_CompileMode != noCompile && m_DisplayList ) 
  {
    ScheduleToUpdateDisplayList();
  }
}



  
//--------------------------------------------------
//
//    Choose compile mode
//
//--------------------------------------------------
void Shape3D::SetCompileMode(enum compileModes newmode) 
{
  m_CompileMode = newmode;
  if( m_CompileMode == noCompile && m_DisplayList ) 
  {
    ScheduleToUpdateDisplayList();
  }
}



//--------------------------------------------------
//
//      Choose color for drawing
//
//--------------------------------------------------
void Shape3D::SetColor(const Shape3D::ColorType &newcolor ) 
{

  m_Color = newcolor;

  ContainerType::iterator it = m_Components.begin();
  while( it != m_Components.end() )
  {
    (*it)->SetColor( newcolor );
    ++it;
  }
  
  ScheduleToUpdateDisplayList();
  
}


//--------------------------------------------------
//
//      Choose transparency for drawing
//
//--------------------------------------------------
void Shape3D::SetTransparency(GLfloat transparency) 
{
  
  m_Transparency = transparency;
  
  ContainerType::iterator it = m_Components.begin();
  while( it != m_Components.end() )
  {
    (*it)->SetTransparency( transparency );
    ++it;
  }

  ScheduleToUpdateDisplayList();

}


//--------------------------------------------------
//
//    Set the selection for computing current position
//    during the next OpenGL redraw
//
//--------------------------------------------------
void Shape3D::SetAutoSensing( bool sensing ) const
{
  m_AutoSensing = sensing;
  
  ContainerType::const_iterator it = m_Components.begin();
  while( it != m_Components.end() )
  {
    (*it)->SetAutoSensing( sensing );
    ++it;
  }

}


//--------------------------------------------------
//
//    Set the selection for restoring the transform
//    during the next OpenGL redraw
//
//--------------------------------------------------
void Shape3D::SetRestoreTransform( bool restoring ) const
{
  m_RestoreTransform = restoring;
 
  ContainerType::const_iterator it = m_Components.begin();
  while( it != m_Components.end() )
  {
    (*it)->SetRestoreTransform( restoring );
    ++it;
  }

}



//--------------------------------------------------
//
//    Return the selection for computing current position
//    during the next OpenGL redraw
//
//--------------------------------------------------
bool Shape3D::GetAutoSensing( void ) const
{
  return m_AutoSensing;
}
  


   
//--------------------------------------------------
//
//      Prepare color in OpenGL
//
//--------------------------------------------------
void Shape3D::glColor(void) const 
{
  glColor3f(  m_Color.GetRed(), 
              m_Color.GetGreen(), 
              m_Color.GetBlue()   );
}

 


//--------------------------------------------------
//
//      Prepare color in OpenGL
//
//--------------------------------------------------
void Shape3D::glMaterialColor(void) const 
{
  GLfloat color[] = { m_Color.GetRed(), 
                       m_Color.GetGreen(), 
                       m_Color.GetBlue(), 
                       (GLfloat)(1.0-m_Transparency) };
  glMaterialfv(GL_FRONT,GL_DIFFUSE,color);
}




//--------------------------------------------------
//
//      Remove display list
//
//--------------------------------------------------
void Shape3D::RemoveDisplayList(void)
{
  m_ScheduledToRemoveDisplayList = true;
}




//--------------------------------------------------
//
//      Add a Component
//
//--------------------------------------------------
void Shape3D::AddComponent(Shape3D * newcomponent) 
{

  if( newcomponent == 0 )
  {
    return;
  }
  
  newcomponent->m_Father = this;
  m_Components.push_back( newcomponent );
}



//--------------------------------------------------
//
//      Remove a Component
//
//--------------------------------------------------
void Shape3D::RemoveComponent(Shape3D * oldcomponent) 
{

  if( oldcomponent == 0 )
  {
    return;
  }
  
  oldcomponent->m_Father = 0;
  m_Components.remove( oldcomponent );
  
}



//--------------------------------------------------
//
//      Get First Component
//
//--------------------------------------------------
Shape3D::ContainerType::iterator 
Shape3D::GetFirstComponent(void)
{
   return m_Components.begin();
}



//--------------------------------------------------
//
//      Get the current position in OpenGL
//      Model Space
//
//--------------------------------------------------
void
Shape3D::ComputeCurrentTransform( void ) const
{
  glGetFloatv( GL_MODELVIEW_MATRIX, m_Transform );
}


//--------------------------------------------------
//
//      Get the current position in OpenGL
//      Model Space
//
//--------------------------------------------------
const Shape3D::PointType &
Shape3D::GetCurrentPosition(void) const
{
  PointType here;
  here = 0.0, 0.0, 0.0;
  m_CurrentPosition = ComputeCurrentPosition( here );
  return m_CurrentPosition;
}



//--------------------------------------------------
//
//      Get the current position in OpenGL
//      Model Space
//
//--------------------------------------------------
Shape3D::PointType
Shape3D::ComputeCurrentPosition(const PointType & pnt) const
{
  const GLfloat *m = m_Transform;
  PointType result;
  double  d =   m[3] * pnt[0] + m[7] * pnt[1] + m[11] * pnt[2] + m[15];
  result[0] = ( m[0] * pnt[0] + m[4] * pnt[1] + m[ 8] * pnt[2] + m[12] ) / d;
  result[1] = ( m[1] * pnt[0] + m[5] * pnt[1] + m[ 9] * pnt[2] + m[13] ) / d;
  result[2] = ( m[2] * pnt[0] + m[6] * pnt[1] + m[10] * pnt[2] + m[14] ) / d;

  return result;
}



//--------------------------------------------------
//
//      Get the current orientation in OpenGL
//      Model Space
//
//--------------------------------------------------
Shape3D::VectorType
Shape3D::ComputeCurrentOrientation(const VectorType & vec ) const
{
  const GLfloat *m = m_Transform;
  VectorType result;
  result[0] = ( m[0] * vec[0] + m[4] * vec[1] + m[ 8] * vec[2]  );
  result[1] = ( m[1] * vec[0] + m[5] * vec[1] + m[ 9] * vec[2]  );
  result[2] = ( m[2] * vec[0] + m[6] * vec[1] + m[10] * vec[2]  );
  return result;
}



//--------------------------------------------------
//
//    Draw Geometry
//
//--------------------------------------------------
void Shape3D::DrawGeometry(void) const
{
  std::cerr << "Shape3D::DrawGeometry this method should not be called";
  std::cerr << std::endl;
}


//--------------------------------------------------
//
//    Redraw ask the eventual Observer to refresh
//    their views
//
//--------------------------------------------------
void Shape3D::Redraw(void) const
{
    InvokeEvent( RedrawEvent );
}



//--------------------------------------------------
//
//    Invoke an event in the top of the hierarchy
//
//--------------------------------------------------
void Shape3D::InvokeEvent( EventIds event ) const
{
  
  LightObject::InvokeEvent( event );

  if( m_Father ) 
  {
    m_Father->InvokeEvent( event );
  }


}




//--------------------------------------------------
//
//      draw the shape
//
//--------------------------------------------------
void Shape3D::glDraw(void) const 
{

  if( m_ScheduledToRemoveDisplayList && m_DisplayList ) 
  {
    glDeleteLists( m_DisplayList, 1 );
    m_ScheduledToRemoveDisplayList = false;
    m_DisplayList = 0;
    return;
  }
  
  if( m_ScheduledToUpdateDisplayList && m_DisplayList ) 
  {
    glDeleteLists( m_DisplayList, 1 );
    m_ScheduledToUpdateDisplayList = false;
    m_DisplayList = 0;
  }
  
  if( m_CompileMode != noCompile && m_DisplayList ) 
  {
    glCallList( m_DisplayList );
    return;
  }


  switch( m_CompileMode ) 
  {
    case noCompile:
    {
      if( m_DisplayList ) 
      {
        glDeleteLists( m_DisplayList, 1 );
        m_DisplayList = 0;
      }
      break;
    }
    case onlyCompile: 
    {
      m_DisplayList = glGenLists( 1 ); 
      glNewList( m_DisplayList, GL_COMPILE );
      break;
    }
    case compileExecute: 
    {
      m_DisplayList = glGenLists( 1 ); 
      glNewList( m_DisplayList, GL_COMPILE_AND_EXECUTE );
      break;
    }
  }

  switch( m_DrawingMode ) 
  {
    case none     : 
        {
          break;
        }
    case points   : 
        {
          glDisable( GL_LIGHTING ); 
          glColor();          
          break; 
        }
    case lines    : 
        {
          glDisable( GL_LIGHTING ); 
          glColor();          
          break;
        }
    case triangles: 
        {
        glEnable( GL_LIGHTING ); 
        glMaterialColor();  
        break;
        }
  }

  if( m_AutoSensing ) 
  {
    ComputeCurrentTransform();
  }

  if( m_RestoreTransform )
  {
    glLoadMatrixf( m_Transform );
  }

  DrawGeometry();

  if( m_DisplayList != 0 ) 
  {
    glEndList();
  }

  
}



} // end namespace li



