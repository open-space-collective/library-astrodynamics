////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Astrodynamics
/// @file           OpenSpaceToolkit/Astrodynamics/Flight/Profile/State.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __OpenSpaceToolkit_Astrodynamics_Flight_Profile_State__
#define __OpenSpaceToolkit_Astrodynamics_Flight_Profile_State__

#include <OpenSpaceToolkit/Physics/Coordinate/Frame.hpp>
#include <OpenSpaceToolkit/Physics/Time/Instant.hpp>

#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Transformations/Rotations/RotationMatrix.hpp>
#include <OpenSpaceToolkit/Mathematics/Objects/Vector.hpp>

#include <OpenSpaceToolkit/Core/Types/Shared.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ostk
{
namespace astro
{
namespace flight
{
namespace profile
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using ostk::core::types::Shared ;

using ostk::math::obj::Vector3d ;
using ostk::math::geom::d3::trf::rot::Quaternion ;

using ostk::physics::time::Instant ;
using ostk::physics::coord::Frame ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Spacecraft flight profile state

class State
{

    public:

                                State                                       (   const   Instant&                    anInstant,
                                                                                const   Vector3d&                   aPosition,
                                                                                const   Vector3d&                   aVelocity,
                                                                                const   Quaternion&                 anAttitude,
                                                                                const   Vector3d&                   anAngularVelocity,
                                                                                const   Shared<const Frame>&        aReferenceFrame                             ) ;

        bool                    operator ==                                 (   const   State&                      aState                                      ) const ;

        bool                    operator !=                                 (   const   State&                      aState                                      ) const ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   State&                      aState                                      ) ;

        bool                    isDefined                                   ( ) const ;

        const Instant&          accessInstant                               ( ) const ;

        const Vector3d&         accessPosition                              ( ) const ;

        const Vector3d&         accessVelocity                              ( ) const ;

        const Quaternion&       accessAttitude                              ( ) const ;

        const Vector3d&         accessAngularVelocity                       ( ) const ;

        Instant                 getInstant                                  ( ) const ;

        Vector3d                getPosition                                 ( ) const ;

        Vector3d                getVelocity                                 ( ) const ;

        Quaternion              getAttitude                                 ( ) const ;

        Vector3d                getAngularVelocity                          ( ) const ;

        Shared<const Frame>     getFrame                                    ( ) const ;

        State                   inFrame                                     (   const   Shared<const Frame>&        aFrameSPtr                                  ) const ;

        static State            Undefined                                   ( ) ;

    private:

        Instant                 instant_ ;
        Vector3d                position_ ;
        Vector3d                velocity_ ;
        Quaternion              attitude_ ;
        Vector3d                angularVelocity_ ;
        Shared<const Frame>     frameSPtr_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
