/******************************************************************************
 *                                                                            *
 * Copyright (C) 2018 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @file objectsLib.h
 * @authors: Fabrizio Bottarel <fabrizio.bottarel@iit.it>
 */

#include <vtkSmartPointer.h>
#include <vtkCommand.h>
#include <vtkProperty.h>
#include <vtkPolyDataMapper.h>
#include <vtkPointData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkSuperquadric.h>
#include <vtkTransform.h>
#include <vtkSampleFunction.h>
#include <vtkContourFilter.h>
#include <vtkActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkCamera.h>
#include <vtkInteractorStyleSwitch.h>
#include <vtkMatrix4x4.h>

#include <yarp/sig/all.h>
#include <yarp/math/Math.h>


class Object
{

protected:
    vtkSmartPointer<vtkPolyDataMapper> vtk_mapper;
    vtkSmartPointer<vtkActor> vtk_actor;

public:

    /****************************************************************/
    vtkSmartPointer<vtkActor> &get_actor();

};

class Points : public Object
{
protected:
    vtkSmartPointer<vtkPoints> vtk_points;
    vtkSmartPointer<vtkUnsignedCharArray> vtk_colors;
    vtkSmartPointer<vtkPolyData> vtk_polydata;
    vtkSmartPointer<vtkVertexGlyphFilter> vtk_glyphFilter;

public:

    /****************************************************************/
    Points(const yarp::sig::PointCloud<yarp::sig::DataXYZRGBA> &points, const int point_size);

    /****************************************************************/
    void set_points(const yarp::sig::PointCloud<yarp::sig::DataXYZRGBA> &points);

    /****************************************************************/
    bool set_colors(const yarp::sig::PointCloud<yarp::sig::DataXYZRGBA> &points);

    /****************************************************************/
    vtkSmartPointer<vtkPolyData> &get_polydata();

};

class Superquadric : public Object
{
protected:
    vtkSmartPointer<vtkSuperquadric> vtk_superquadric;
    vtkSmartPointer<vtkSampleFunction> vtk_sample;
    vtkSmartPointer<vtkContourFilter> vtk_contours;
    vtkSmartPointer<vtkTransform> vtk_transform;

    /*
     * Parameters:
     * epsilon_2 is e (roundedness/squareness east/west - theta roundedness)
     * epsilon_1 is n (roundedness/sqareness north/south - phi roundedness)
     * scale is sx, sy, sz
     * center is cx, cy, cz
     * translation and rotation parameters are bound to the vtkTransform object
     */

public:

    /****************************************************************/
    Superquadric(const yarp::sig::Vector &r, const double color);

    /****************************************************************/
    void set_parameters(const yarp::sig::Vector &r);

    /****************************************************************/
    yarp::sig::Vector getCenter();

    /****************************************************************/
    yarp::sig::Vector getAxesSize();

    /****************************************************************/
    yarp::sig::Vector getOrientationXYZW();

};
