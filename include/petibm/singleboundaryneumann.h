/**
 * \file singleboundaryneumann.h
 * \brief Definition of the class `SingleBoundaryNeumann`.
 * \author Anush Krishnan (anush@bu.edu)
 * \author Olivier Mesnard (mesnardo@gwu.edu)
 * \author Pi-Yueh Chuang (pychuang@gwu.edu)
 * \copyright MIT.
 */


# pragma once

// here goes headers from our PetIBM
# include <petibm/singleboundary.h>


namespace petibm
{
namespace boundary
{

/**
 * \brief An implementation of SingleBoundaryBase for Neumann BC.
 * \see boundaryModule, petibm::type::SingleBoundary, petibm::boundary::createSingleBoundary
 * \ingroup boundaryModule
 */
class SingleBoundaryNeumann : public SingleBoundaryBase
{
public:

    /**
     * \brief Constructor.
     * \param mesh [in] a Mesh instance.
     * \param loc [in] the location of the target boundary.
     * \param field [in] the target field.
     * \param value [in] BC value.
     */
    SingleBoundaryNeumann(const type::Mesh &mesh, const type::BCLoc &loc, 
            const type::Field &field, const PetscReal &value); 

    /** \copydoc SingleBoundaryBase::~SingleBoundaryBase */
    virtual ~SingleBoundaryNeumann() = default;

protected:

    // implementation of SingleBoundaryBase::setGhostICsKernel
    virtual PetscErrorCode setGhostICsKernel(
            const PetscReal &targetValue, type::GhostPointInfo &p);

    // implementation of SingleBoundaryBase::updateEqsKernel
    virtual PetscErrorCode updateEqsKernel(const PetscReal &targetValue,
            const PetscReal &dt, type::GhostPointInfo &p);

}; // SingleBoundaryNeumann

} // end of namespace boundary
} // end of namespace petibm