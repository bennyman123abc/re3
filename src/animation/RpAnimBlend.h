#pragma once

class CAnimBlendNode;
class CAnimBlendAssociation;
class CAnimBlendClumpData;
struct AnimBlendFrameData;

struct AnimBlendFrameUpdateData
{
	int foobar;
	CAnimBlendNode *nodes[16];
};

extern RwInt32 &ClumpOffset;
#define RPANIMBLENDCLUMPDATA(o) (RWPLUGINOFFSET(CAnimBlendClumpData*, o, ClumpOffset))

bool RpAnimBlendPluginAttach(void);
CAnimBlendAssociation *RpAnimBlendGetNextAssociation(CAnimBlendAssociation *assoc);
CAnimBlendAssociation *RpAnimBlendGetNextAssociation(CAnimBlendAssociation *assoc, uint32 mask);
void RpAnimBlendAllocateData(RpClump *clump);

void RpAnimBlendClumpSetBlendDeltas(RpClump *clump, uint32 mask, float delta);
void RpAnimBlendClumpRemoveAllAssociations(RpClump *clump);
void RpAnimBlendClumpRemoveAssociations(RpClump *clump, uint32 mask);
void RpAnimBlendClumpInit(RpClump *clump);
bool RpAnimBlendClumpIsInitialized(RpClump *clump);
AnimBlendFrameData *RpAnimBlendClumpFindFrame(RpClump *clump, const char *name);
void FillFrameArrayCallBack(AnimBlendFrameData *frame, void *arg);
CAnimBlendAssociation *RpAnimBlendClumpGetAssociation(RpClump *clump, uint32 id);
CAnimBlendAssociation *RpAnimBlendClumpGetMainAssociation(RpClump *clump, CAnimBlendAssociation **assocRet, float *blendRet);
CAnimBlendAssociation *RpAnimBlendClumpGetMainPartialAssociation(RpClump *clump);
CAnimBlendAssociation *RpAnimBlendClumpGetMainAssociation_N(RpClump *clump, int n);
CAnimBlendAssociation *RpAnimBlendClumpGetMainPartialAssociation_N(RpClump *clump, int n);
CAnimBlendAssociation *RpAnimBlendClumpGetFirstAssociation(RpClump *clump, uint32 mask);
CAnimBlendAssociation *RpAnimBlendClumpGetFirstAssociation(RpClump *clump);


extern CAnimBlendClumpData *&gpAnimBlendClump;
void FrameUpdateCallBack(AnimBlendFrameData *frame, void *arg);