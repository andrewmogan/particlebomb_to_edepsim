#ifndef __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSFACTORY_CXX__
#define __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSFACTORY_CXX__

#include <TFile.h>
#include <TTree.h>
#include <TBits.h>
#include <TObjString.h>

#include "ParticleBombKinematicsFactory.h"
#include "ParticleBombKinematicsGenerator.h"

particlebomb_to_edepsim::ParticleBombKinematicsFactory::ParticleBombKinematicsFactory(
    EDepSim::UserPrimaryGeneratorMessenger* parent)
    : EDepSim::VKinematicsFactory("ParticleBomb",parent),
      fInputFile("not-open"), fGeneratorName("GENIE"), 
      fOrder("consecutive"), fFirstEvent(0) {

    fInputFileCMD = new G4UIcmdWithAString(CommandName("input"),this);
    fInputFileCMD->SetGuidance("Set the input file.");
    fInputFileCMD->SetParameterName("name",false);

    fGeneratorNameCMD = new G4UIcmdWithAString(CommandName("generator"),this);
    fGeneratorNameCMD->SetGuidance("Set the name of the kinematics source.");
    fGeneratorNameCMD->SetParameterName("generator",false);

    fOrderCMD = new G4UIcmdWithAString(CommandName("order"),this);
    fOrderCMD->SetGuidance("Set order that events in the file are used.");
    fOrderCMD->SetParameterName("order",false);
    fOrderCMD->SetCandidates("consecutive stride random");

    fFirstEventCMD = new G4UIcmdWithAnInteger(CommandName("first"),this);
    fFirstEventCMD->SetGuidance("Set the first event to generate.");
    fFirstEventCMD->SetParameterName("number",false);
}

particlebomb_to_edepsim::ParticleBombKinematicsFactory::~ParticleBombKinematicsFactory() {
    delete fInputFileCMD;
    delete fTreeNameCMD;
    delete fGeneratorNameCMD;
    delete fOrderCMD;
    delete fFirstEventCMD;
}

void particlebomb_to_edepsim::ParticleBombKinematicsFactory::SetNewValue(G4UIcommand* command,
                                                                         G4String newValue) {
    if (command == fInputFileCMD) {
        SetInputFile(newValue);
    }
    else if (command == fGeneratorNameCMD) {
        SetGeneratorName(newValue);
    }
    else if (command == fOrderCMD) {
        SetOrder(newValue);
    }
    else if (command == fFirstEventCMD) {
        SetFirstEvent(fFirstEventCMD->GetNewIntValue(newValue));
    }
}

EDepSim::VKinematicsGenerator* particlebomb_to_edepsim::ParticleBombKinematicsFactory::GetGenerator() {
    EDepSim::VKinematicsGenerator* kine
        = new particlebomb_to_edepsim::ParticleBombKinematicsGenerator(GetGeneratorName(),
                                                                       GetInputFile(),
                                                                       GetOrder(),
                                                                       GetFirstEvent());
    return kine;
}

#endif
