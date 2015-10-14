#include "params.hpp"
#include <boost/archive/archive_exception.hpp>

using namespace std;

namespace cctag
{
Parameters::Parameters(const std::size_t nCrowns)
    : _cannyThrLow( kDefaultCannyThrLow )
    , _cannyThrHigh( kDefaultCannyThrHigh )
    , _distSearch( kDefaultDistSearch )
    , _thrGradientMagInVote( kDefaultThrGradientMagInVote )
    , _angleVoting( kDefaultAngleVoting )
    , _ratioVoting( kDefaultRatioVoting )
    , _averageVoteMin( kDefaultAverageVoteMin )
    , _thrMedianDistanceEllipse( kDefaultThrMedianDistanceEllipse )
    , _maximumNbSeeds( kDefaultMaximumNbSeeds )
    , _maximumNbCandidatesLoopTwo( kDefaultMaximumNbCandidatesLoopTwo )
    , _nCrowns( nCrowns )
    , _minPointsSegmentCandidate( kDefaultMinPointsSegmentCandidate )
    , _minVotesToSelectCandidate( kDefaultMinVotesToSelectCandidate )
    , _threshRobustEstimationOfOuterEllipse( kDefaultThreshRobustEstimationOfOuterEllipse )
    , _ellipseGrowingEllipticHullWidth( kDefaultEllipseGrowingEllipticHullWidth )
    , _windowSizeOnInnerEllipticSegment( kDefaultWindowSizeOnInnerEllipticSegment )
    , _numberOfMultiresLayers( kDefaultNumberOfMultiresLayers )
    , _numberOfProcessedMultiresLayers( kDefaultNumberOfProcessedMultiresLayers )
    , _numCutsInIdentStep( kDefaultNumCutsInIdentStep )
    , _numSamplesOuterEdgePointsRefinement( kDefaultNumSamplesOuterEdgePointsRefinement )
    , _cutsSelectionTrials( kDefaultCutsSelectionTrials )
    , _sampleCutLength( kDefaultSampleCutLength )
    , _minIdentProba( kDefaultMinIdentProba )
    , _useLMDif( kDefaultUseLMDif )
    , _searchForAnotherSegment( kDefaultSearchForAnotherSegment )
    , _writeOutput( kDefaultWriteOutput )
    , _doIdentification( kDefaultDoIdentification )
    , _maxEdges( kDefaultMaxEdges )
    , _debugDir( "" )
{
    _nCircles = 2*_nCrowns;
}

void Parameters::setDebugDir( const std::string& debugDir )
{
    struct stat st = {0};

    std::string dir = debugDir;
    char   dirtail = dir[ dir.size()-1 ];
    if( dirtail != '/' ) {
        _debugDir = debugDir + "/";
    } else {
        _debugDir = debugDir;
    }

    if (::stat( _debugDir.c_str(), &st) == -1) {
        ::mkdir( _debugDir.c_str(), 0700);
    }
}

template<class Archive>
void Parameters::private_serialize(Archive & ar, const unsigned int version)
{
    ar & BOOST_SERIALIZATION_NVP( _cannyThrLow );
    ar & BOOST_SERIALIZATION_NVP( _cannyThrHigh );
    ar & BOOST_SERIALIZATION_NVP( _distSearch );
    ar & BOOST_SERIALIZATION_NVP( _thrGradientMagInVote );
    ar & BOOST_SERIALIZATION_NVP( _angleVoting );
    ar & BOOST_SERIALIZATION_NVP( _ratioVoting );
    ar & BOOST_SERIALIZATION_NVP( _averageVoteMin);
    ar & BOOST_SERIALIZATION_NVP( _thrMedianDistanceEllipse);
    ar & BOOST_SERIALIZATION_NVP( _maximumNbSeeds);
    ar & BOOST_SERIALIZATION_NVP( _maximumNbCandidatesLoopTwo);
    ar & BOOST_SERIALIZATION_NVP( _nCrowns );
    ar & BOOST_SERIALIZATION_NVP( _minPointsSegmentCandidate );
    ar & BOOST_SERIALIZATION_NVP( _minVotesToSelectCandidate );
    ar & BOOST_SERIALIZATION_NVP( _threshRobustEstimationOfOuterEllipse );
    ar & BOOST_SERIALIZATION_NVP( _ellipseGrowingEllipticHullWidth );
    ar & BOOST_SERIALIZATION_NVP( _windowSizeOnInnerEllipticSegment );
    ar & BOOST_SERIALIZATION_NVP( _numberOfMultiresLayers );
    ar & BOOST_SERIALIZATION_NVP( _numberOfProcessedMultiresLayers );
    ar & BOOST_SERIALIZATION_NVP( _numCutsInIdentStep );
    ar & BOOST_SERIALIZATION_NVP( _numSamplesOuterEdgePointsRefinement );
    ar & BOOST_SERIALIZATION_NVP( _cutsSelectionTrials );
    ar & BOOST_SERIALIZATION_NVP( _sampleCutLength );
    ar & BOOST_SERIALIZATION_NVP( _minIdentProba );
    ar & BOOST_SERIALIZATION_NVP( _useLMDif );
    ar & BOOST_SERIALIZATION_NVP( _searchForAnotherSegment );
    ar & BOOST_SERIALIZATION_NVP( _writeOutput );
    ar & BOOST_SERIALIZATION_NVP( _doIdentification );
    ar & BOOST_SERIALIZATION_NVP( _maxEdges );
    _nCircles = 2*_nCrowns;
}

void Parameters::serialize(boost::archive::xml_iarchive & ar, const unsigned int version)
{
    try {
        private_serialize( ar, version );
    } catch( boost::archive::archive_exception& e ) {
        cerr << "Caught an archive exception " << e.what() << endl;
    }
}

void Parameters::serialize(boost::archive::xml_oarchive & ar, const unsigned int version)
{
    try {
        private_serialize( ar, version );
    } catch( boost::archive::archive_exception& e ) {
        cerr << "Caught an archive exception " << e.what() << endl;
    }
}


} // namespace cctag
