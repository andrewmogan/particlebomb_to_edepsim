/**
 * \file ParticleBombKinematicsGenerator.h
 *
 * \ingroup particlebomb_to_edepsim
 * 
 * \brief Class def header for a class ParticleBombKinematicsGenerator
 *
 * @author amogan
 */

/** \addtogroup particlebomb_to_edepsim

    @{*/
#ifndef __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSGENERATOR_H__
#define __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSGENERATOR_H__

#include <vector>

#include "kinem/EDepSimVKinematicsGenerator.hh"

class TFile;
class TTree;
class TBits;
class TObjString;
class G4Event;

namespace particlebomb_to_edepsim {class ParticleBombKinematicsGenerator;}

  /**
     \class ParticleBombKinematicsGenerator
     User defined class ParticleBombKinematicsGenerator ... these comments are used to generate
     doxygen documentation!
  */
class particlebomb_to_edepsim::ParticleBombKinematicsGenerator : public EDepSim::VKinematicsGenerator { 
    public:
    
        ParticleBombKinematicsGenerator(const G4String& name, 
                                      const G4String& fileName,
                                      const G4String& order,
                                      int firstEvent);

        virtual ~ParticleBombKinematicsGenerator(); 
        
        /// Add a primary vertex to the event.
        virtual GeneratorStatus GeneratePrimaryVertex(
        G4Event* evt, const G4LorentzVector& position);

        /// Get the name of the open kinematics file.
        virtual G4String GetInputName();

};

#endif
/** @} */ // end of doxygen group 

