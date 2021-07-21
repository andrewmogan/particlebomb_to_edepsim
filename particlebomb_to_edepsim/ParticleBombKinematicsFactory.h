/**
 * \file ParticleBombKinematicsFactory.h
 *
 * \ingroup particlebomb_to_edepsim
 * 
 * \brief Class def header for a class ParticleBombKinematicsFactory
 *
 * @author amogan
 */

/** \addtogroup particlebomb_to_edepsim

    @{*/
#ifndef __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSFACTORY_H__
#define __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSFACTORY_H__

#include "kinem/EDepSimVKinematicsFactory.hh"

class G4VPrimaryGenerator;
namespace particlebomb_to_edepsim {class ParticleBombKinematicsGenerator;}

  /**
     \class ParticleBombKinematicsFactory
     User defined class ParticleBombKinematicsFactory ... these comments are used to generate
     doxygen documentation!
  */

namespace particlebomb_to_edepsim {class ParticleBombKinematicsFactory;}
class particlebomb_to_edepsim::ParticleBombKinematicsFactory : public EDepSim::VKinematicsFactory {

public:

    ParticleBombKinematicsFactory(EDepSim::UserPrimaryGeneratorMessenger* fParent);
    virtual ~ParticleBombKinematicsFactory();

    /// Return a new generator enclosing the current factory state.  The new
    /// generator method is pure virtual so it must be implemented by derived
    /// classes.
    virtual EDepSim::VKinematicsGenerator* GetGenerator();

    /// Set the input file to read.
    virtual void SetInputFile(const G4String& name) {fInputFile=name;}

    /// Get the input file to read.
    virtual const G4String& GetInputFile() const {return fInputFile;}

    /// Set the generator name.  This is the name of the program that
    /// generated the rooTracker tree, and will be saved as documentation in
    /// the output file.
    virtual void SetGeneratorName(const G4String& name) {fGeneratorName = name;}

    /// Get the generator name.
    virtual const G4String& GetGeneratorName() const {return fGeneratorName;}

    /// Set the order that events in the input file will be used.
    virtual void SetOrder(const G4String& order) {fOrder = order;}

    /// Get the order that events in the input file will be used.
    virtual G4String GetOrder() {return fOrder;}

    /// Set the first event to read.
    virtual void SetFirstEvent(int f) {fFirstEvent=f;}

    /// Get the first event to read.
    virtual int GetFirstEvent() const {return fFirstEvent;}

    virtual void SetNewValue(G4UIcommand* command,G4String newValue);

private:
    /// The root file with the RooTracker tree.
    G4String fInputFile;

    /// The name of the generater that created the rooTracker tree (eg GENIE,
    /// NEUT, &c).
    G4String fGeneratorName;

    /// The order that events in the input file will be used.
    G4String fOrder;

    /// The first event to read in the file.
    int fFirstEvent;

    G4UIcmdWithAString* fInputFileCMD;
    G4UIcmdWithAString* fTreeNameCMD;
    G4UIcmdWithAString* fGeneratorNameCMD;
    G4UIcmdWithAString* fOrderCMD;
    G4UIcmdWithAnInteger* fFirstEventCMD;

};

#endif
/** @} */ // end of doxygen group 

