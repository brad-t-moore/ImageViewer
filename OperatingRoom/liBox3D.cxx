//--------------------------------------------
//
//     Project:   Operating Room
//
//     Author:    Luis Ibanez
//
//     Division of Neurosugery
//     Department of Surgery
//     University of North Carolina
//     Chapel Hill, NC 27599
//
//--------------------------------------------


#include <liBox3D.h>


namespace li {

//--------------------------------------------------
//
//    Constructor
//
//--------------------------------------------------
Box3D::Box3D(void)  
{
  m_Width   = 1.0;
  m_Height  = 1.0;
  m_Length  = 1.0;
}





//--------------------------------------------------
//
//    Set Width
//
//--------------------------------------------------
void 
Box3D::SetWidth( double width )
{
  m_Width  = width;
}



//--------------------------------------------------
//
//    Set Height
//
//--------------------------------------------------
void 
Box3D::SetHeight( double height )
{
  m_Height  = height;
}




//--------------------------------------------------
//
//    Set Length
//
//--------------------------------------------------
void 
Box3D::SetLength( double length )
{
  m_Length  = length;
}





//--------------------------------------------------
//
//    Get Width
//
//--------------------------------------------------
double 
Box3D::GetWidth( void ) const
{
  return m_Width;
}


//--------------------------------------------------
//
//    Get Height
//
//--------------------------------------------------
double 
Box3D::GetHeight( void ) const
{
  return m_Height;
}


//--------------------------------------------------
//
//    Get Length
//
//--------------------------------------------------
double 
Box3D::GetLength( void ) const
{
  return m_Length;
}






//--------------------------------------------------
//
//    draw Geometric representation
//
//--------------------------------------------------
void 
Box3D::DrawGeometry(void)  const 
{

    const GLdouble l2 = (GLdouble)m_Length/(GLdouble)2.0;
    const GLdouble w2 = (GLdouble)m_Width/(GLdouble)2.0;
    const GLdouble h  = (GLdouble)m_Height;

    glPushMatrix();

    if( GetDrawingMode() == triangles ) 
    {
      glBegin(GL_QUADS);

      glNormal3d(0.0,1.0, 0.0);
      glVertex3d(-l2, w2, 0.0);
      glVertex3d(-l2, w2,   h);
      glVertex3d( l2, w2,   h);
      glVertex3d( l2, w2, 0.0);

      glNormal3d(0.0,-1.0,0.0);
      glVertex3d(-l2,-w2, 0.0);
      glVertex3d( l2,-w2, 0.0);
      glVertex3d( l2,-w2,   h);
      glVertex3d(-l2,-w2,   h);

      glNormal3d(-1.0,0.0,0.0);
      glVertex3d(-l2, w2, 0.0);
      glVertex3d(-l2,-w2, 0.0);
      glVertex3d(-l2,-w2,   h);
      glVertex3d(-l2, w2,   h);

      glNormal3d( 1.0,0.0,0.0);
      glVertex3d( l2, w2, 0.0);
      glVertex3d( l2, w2,   h);
      glVertex3d( l2,-w2,   h);
      glVertex3d( l2,-w2, 0.0);

      glNormal3d(0.0,0.0,-1.0);
      glVertex3d(-l2, w2, 0.0);
      glVertex3d( l2, w2, 0.0);
      glVertex3d( l2,-w2, 0.0);
      glVertex3d(-l2,-w2, 0.0);

      glNormal3d(0.0,0.0,1.0);
      glVertex3d(-l2, w2,   h);
      glVertex3d(-l2,-w2,   h);
      glVertex3d( l2,-w2,   h);
      glVertex3d( l2, w2,   h);

      glEnd();

    }

    if( GetDrawingMode()== lines ) 
    {
      glBegin(GL_LINE_LOOP);
        glVertex3d(-l2, w2,   h);
        glVertex3d(-l2,-w2,   h);
        glVertex3d( l2,-w2,   h);
        glVertex3d( l2, w2,   h);
      glEnd();
      glBegin(GL_LINE_LOOP);
        glVertex3d(-l2, w2, 0.0);
        glVertex3d(-l2,-w2, 0.0);
        glVertex3d( l2,-w2, 0.0);
        glVertex3d( l2, w2, 0.0);
      glEnd();
      glBegin(GL_LINES);
        glVertex3d( l2,-w2, 0.0);
        glVertex3d( l2,-w2,   h);
        glVertex3d( l2, w2, 0.0);
        glVertex3d( l2, w2,   h);
        glVertex3d(-l2,-w2, 0.0);
        glVertex3d(-l2,-w2,   h);
        glVertex3d(-l2, w2, 0.0);
        glVertex3d(-l2, w2,   h);
      glEnd();
    }

    glPopMatrix();

}




} // end namespace li


