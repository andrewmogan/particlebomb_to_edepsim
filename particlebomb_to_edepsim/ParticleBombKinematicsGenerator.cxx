#ifndef __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSGENERATOR_CXX__
#define __PARTICLEBOMB_TO_EDEPSIM_PARTICLEBOMBKINEMATICSGENERATOR_CXX__

// std includes
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>

// Geant4 includes
#include <globals.hh>
#include <G4Event.hh>
#include <G4PrimaryVertex.hh>
#include <G4PrimaryParticle.hh>
#include <G4ParticleTable.hh>
#include <G4IonTable.hh>
#include <G4ParticleDefinition.hh>
#include <G4Tokenizer.hh>
#include <G4UnitsTable.hh>
#include <Randomize.hh>

// ROOT includes
#include <TFile.h>
#include <TBits.h>
#include <TObjString.h>
#include <TTree.h>

// EDepSim includes
#include "EDepSimVertexInfo.hh"
#include "kinem/EDepSimKinemPassThrough.hh"
#include "kinem/EDepSimRooTrackerKinematicsGenerator.hh"
#include "EDepSimLog.hh"

#include "ParticleBombKinematicsGenerator.h"

particlebomb_to_edepsim::ParticleBombKinematicsGenerator::ParticleBombKinematicsGenerator(
    const G4String& name,  std::string filename ) 
    : EDepSim::VKinematicsGenerator(name), fInput(NULL), fNextEntry(0) {

    // Open input HEPEVT file
    std::ifstream infile;
    infile.open(filename);
    if (infile.fail() ) {
        throw std::runtime_error("particlebomb_to_edepsim::ParticleBombKinematicsGenerator::"
                                 " File Not Open");
    }
    EDepSimLog("Opening HEPEVT file " << filename);

    /* Format to write:
     * 0.  status code … 1 = feed in Geant4, other values mean don’t track (but useful for the record)
     * 1.  P DG code … an identifier for a type of a particle. See this reference to decode.
     * 2.  Line number of the first parent particle (0 for initial entries)
     * 3.  Line number of the second parent particle
     * 4.  Line number of the first child particle
     * 5.  Line number of the last child particle
     * 6.  x momentum [GeV/c]
     * 7.  y momentum [GeV/c]
     * 8.  z momentum [GeV/c]
     * 9.  energy [GeV]
     * 10. mass [GeV/c^2]
     * 11. x position [mm]
     * 12. y position [mm]
     * 13. z position [mm]
     * 14. time [ns]
     */

    /* TODO unclear if we need this or not
    //while (order == "stride") {break;}

    //if (firstEvent > 0) {std::cout << "Yup" << std::endl;}
    */
}

particlebomb_to_edepsim::ParticleBombKinematicsGenerator::~ParticleBombKinematicsGenerator() { }

// Check input file name
G4String particlebomb_to_edepsim::ParticleBombKinematicsGenerator::GetInputName() {
    if (!fInput) return G4String("not-open");
    return G4String(fInput->GetName());
}


#endif




























