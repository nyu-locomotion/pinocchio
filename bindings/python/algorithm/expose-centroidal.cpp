//
// Copyright (c) 2015-2019 CNRS INRIA
//

#include "pinocchio/bindings/python/algorithm/algorithms.hpp"
#include "pinocchio/algorithm/centroidal.hpp"

namespace pinocchio
{
  namespace python
  {
    
    void exposeCentroidal()
    {
      using namespace Eigen;

      bp::def("computeCentroidalMomentum",
              &computeCentroidalMomentum<double,0,JointCollectionDefaultTpl>,
              bp::args("Model","Data"),
              "Computes the Centroidal momentum, a.k.a. the total momentum of the system expressed around the center of mass.",
              bp::return_value_policy<bp::return_by_value>());

      bp::def("computeCentroidalMomentum",
              &computeCentroidalMomentum<double,0,JointCollectionDefaultTpl,VectorXd,VectorXd>,
              bp::args("Model","Data",
                       "Joint configuration q (size Model::nq)",
                       "Joint velocity v (size Model::nv)"),
              "Computes the Centroidal momentum, a.k.a. the total momentum of the system expressed around the center of mass.",
              bp::return_value_policy<bp::return_by_value>());
      
      bp::def("computeCentroidalMomentumTimeVariation",
              &computeCentroidalMomentumTimeVariation<double,0,JointCollectionDefaultTpl>,
              bp::args("Model","Data"),
              "Computes the Centroidal momentum and its time derivatives, a.k.a. the total momentum of the system and its time derivative expressed around the center of mass.",
              bp::return_value_policy<bp::return_by_value>());
      
      bp::def("computeCentroidalMomentumTimeVariation",
              &computeCentroidalMomentumTimeVariation<double,0,JointCollectionDefaultTpl,VectorXd,VectorXd,VectorXd>,
              bp::args("Model","Data",
                       "Joint configuration q (size Model::nq)",
                       "Joint velocity v (size Model::nv)",
                       "Joint acceleration a (size Model::nv)"),
              "Computes the Centroidal momentum and its time derivatives, a.k.a. the total momentum of the system and its time derivative expressed around the center of mass.",
              bp::return_value_policy<bp::return_by_value>());
      
      bp::def("ccrba",
              &ccrba<double,0,JointCollectionDefaultTpl,VectorXd,VectorXd>,
              bp::args("Model","Data",
                       "Joint configuration q (size Model::nq)",
                       "Joint velocity v (size Model::nv)"),
              "Computes the centroidal mapping, the centroidal momentum and the Centroidal Composite Rigid Body Inertia, puts the result in Data and returns the centroidal mapping."
              "For the same price, it also computes the total joint jacobians (data.J).",
              bp::return_value_policy<bp::return_by_value>());
      
      bp::def("computeCentroidalMapping",
              &computeCentroidalMapping<double,0,JointCollectionDefaultTpl,VectorXd>,
              bp::args("Model","Data",
                       "Joint configuration q (size Model::nq)"),
              "Computes the centroidal mapping, puts the result in Data.Ag and returns the centroidal mapping.\n"
              "For the same price, it also computes the total joint jacobians (data.J).",
              bp::return_value_policy<bp::return_by_value>());
      
      bp::def("dccrba",
              dccrba<double,0,JointCollectionDefaultTpl,VectorXd,VectorXd>,
              bp::args("Model","Data",
                       "Joint configuration q (size Model::nq)",
                       "Joint velocity v (size Model::nv)"),
              "Computes the time derivative of the centroidal momentum matrix Ag in terms of q and v.\n"
              "For the same price, it also computes the centroidal momentum matrix (data.Ag), the total joint jacobians (data.J) "
              "and the related joint jacobians time derivative (data.dJ)",
              bp::return_value_policy<bp::return_by_value>());
      
      bp::def("computeCentroidalMappingTimeVariation",
              computeCentroidalMappingTimeVariation<double,0,JointCollectionDefaultTpl,VectorXd,VectorXd>,
              bp::args("Model","Data",
                       "Joint configuration q (size Model::nq)",
                       "Joint velocity v (size Model::nv)"),
              "Computes the time derivative of the centroidal momentum matrix Ag, puts the result in Data.Ag and returns the centroidal mapping.\n"
              "For the same price, it also computes the centroidal momentum matrix (data.Ag), the total joint jacobians (data.J) "
              "and the related joint jacobians time derivative (data.dJ)",
              bp::return_value_policy<bp::return_by_value>());
      
    }
    
  } // namespace python
} // namespace pinocchio
