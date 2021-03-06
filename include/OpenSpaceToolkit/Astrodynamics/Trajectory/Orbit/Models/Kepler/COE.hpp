////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Astrodynamics
/// @file           OpenSpaceToolkit/Astrodynamics/Trajectory/Orbit/Models/Kepler/COE.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __OpenSpaceToolkit_Astrodynamics_Trajectory_Orbit_Models_Kepler_COE__
#define __OpenSpaceToolkit_Astrodynamics_Trajectory_Orbit_Models_Kepler_COE__

#include <OpenSpaceToolkit/Physics/Coordinate/Frame.hpp>
#include <OpenSpaceToolkit/Physics/Coordinate/Velocity.hpp>
#include <OpenSpaceToolkit/Physics/Coordinate/Position.hpp>
#include <OpenSpaceToolkit/Physics/Time/Duration.hpp>
#include <OpenSpaceToolkit/Physics/Units/Derived/Angle.hpp>
#include <OpenSpaceToolkit/Physics/Units/Derived.hpp>
#include <OpenSpaceToolkit/Physics/Units/Length.hpp>

#include <OpenSpaceToolkit/Core/Containers/Pair.hpp>
#include <OpenSpaceToolkit/Core/Types/Real.hpp>
#include <OpenSpaceToolkit/Core/Types/Shared.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ostk
{
namespace astro
{
namespace trajectory
{
namespace orbit
{
namespace models
{
namespace kepler
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using ostk::core::types::Shared ;
using ostk::core::types::Real ;
using ostk::core::ctnr::Pair ;

using ostk::physics::units::Length ;
using ostk::physics::units::Derived ;
using ostk::physics::units::Angle ;
using ostk::physics::time::Duration ;
using ostk::physics::coord::Position ;
using ostk::physics::coord::Velocity ;
using ostk::physics::coord::Frame ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Classical Orbital Elements (COE)
///
/// @ref                        https://en.wikipedia.org/wiki/Orbital_elements
/// @ref                        http://help.agi.com/stk/index.htm#stk/vehSat_coordType_classical.htm

class COE
{

    public:

        typedef                 Pair<Position, Velocity>                        CartesianState ;

                                COE                                         (   const   Length&                     aSemiMajorAxis,
                                                                                const   Real&                       anEccentricity,
                                                                                const   Angle&                      anInclination,
                                                                                const   Angle&                      aRaan,
                                                                                const   Angle&                      anAop,
                                                                                const   Angle&                      aTrueAnomaly                                ) ;

        bool                    operator ==                                 (   const   COE&                        aCOE                                        ) const ;

        bool                    operator !=                                 (   const   COE&                        aCOE                                        ) const ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   COE&                        aCOE                                        ) ;

        bool                    isDefined                                   ( ) const ;

        Length                  getSemiMajorAxis                            ( ) const ;

        Real                    getEccentricity                             ( ) const ;

        Angle                   getInclination                              ( ) const ;

        Angle                   getRaan                                     ( ) const ;

        Angle                   getAop                                      ( ) const ;

        Angle                   getTrueAnomaly                              ( ) const ;

        Angle                   getMeanAnomaly                              ( ) const ;

        Angle                   getEccentricAnomaly                         ( ) const ;

        Derived                 getMeanMotion                               (   const   Derived&                    aGravitationalParameter                     ) const ;

        Duration                getOrbitalPeriod                            (   const   Derived&                    aGravitationalParameter                     ) const ;

        COE::CartesianState     getCartesianState                           (   const   Derived&                    aGravitationalParameter,
                                                                                const   Shared<const Frame>&        aFrameSPtr                                  ) const ;

        void                    print                                       (           std::ostream&               anOutputStream,
                                                                                        bool                        displayDecorator                            =   true ) const ;

        static COE              Undefined                                   ( ) ;

        static COE              Cartesian                                   (   const   COE::CartesianState&        aCartesianState,
                                                                                const   Derived&                    aGravitationalParameter                     ) ;

        static Angle            EccentricAnomalyFromTrueAnomaly             (   const   Angle&                      aTrueAnomaly,
                                                                                const   Real&                       anEccentricity                              ) ;

        static Angle            TrueAnomalyFromEccentricAnomaly             (   const   Angle&                      anEccentricAnomaly,
                                                                                const   Real&                       anEccentricity                              ) ;

        static Angle            MeanAnomalyFromEccentricAnomaly             (   const   Angle&                      anEccentricAnomaly,
                                                                                const   Real&                       anEccentricity                              ) ;

        static Angle            EccentricAnomalyFromMeanAnomaly             (   const   Angle&                      aMeanAnomaly,
                                                                                const   Real&                       anEccentricity,
                                                                                const   Real&                       aTolerance                                  ) ;

    private:

        Length                  semiMajorAxis_ ;
        Real                    eccentricity_ ;
        Angle                   inclination_ ;
        Angle                   raan_ ;
        Angle                   aop_ ;
        Angle                   trueAnomaly_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
