// Copyright 2011-2026 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// This file is auto-generated. To regenerate, run the "regenerate-api-stubs.sh"
// script.

#include <cstddef>
#include <cstdint>

// clang-format off
#include "exceptions.h"  // NOLINT
#define BINARYNINJACORE_LIBRARY
#include "binaryninjacore.h"  // NOLINT
// clang-format on

extern "C" {
BINARYNINJACOREAPI BNSimilarityProviderType* BNRegisterSimilarityProviderType(
    const char* name, const char* description,
    BNCustomSimilarityProviderType* type) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProviderType* BNGetSimilarityProviderTypeByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProviderType** BNGetSimilarityProviderTypeList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityProviderTypeList(
    BNSimilarityProviderType** types) {}
BINARYNINJACOREAPI char* BNSimilarityProviderTypeGetName(
    BNSimilarityProviderType* type) {
  return {};
}
BINARYNINJACOREAPI char* BNSimilarityProviderTypeGetDescription(
    BNSimilarityProviderType* type) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProvider* BNSimilarityProviderTypeCreateProvider(
    BNSimilarityProviderType* type, BNSettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNSimilarityProviderTypeGetDefaultSettings(
    BNSimilarityProviderType* type) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProvider* BNCreateCustomSimilarityProvider(
    BNSimilarityProviderType* type, BNCustomSimilarityProvider* callbacks) {
  return {};
}
BINARYNINJACOREAPI void BNSimilarityProviderVisitNode(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* node,
    BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI void BNSimilarityProviderVisitNodeEdge(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* from,
    BNSimilaritySessionNode* to, BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI bool BNSimilarityProviderPerformVisitNode(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* node,
    BNSimilarityProviderResults* results,
    BNSimilaritySessionCompletion* completion) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilarityProviderPerformVisitNodeEdge(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* from,
    BNSimilaritySessionNode* to, BNSimilarityProviderResults* results,
    BNSimilaritySessionCompletion* completion) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityResultId BNSimilarityProviderResultsAddResult(
    BNSimilarityProviderResults* results, const BNSimilarityEntityRef* source,
    const BNSimilarityEntityRef* target, uint8_t similarity,
    uint8_t confidence) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProviderType* BNSimilarityProviderGetType(
    BNSimilarityProvider* provider) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProviderId
BNSimilarityProviderGetId(BNSimilarityProvider* provider) {
  return {};
}
BINARYNINJACOREAPI char* BNSimilarityProviderGetName(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* node,
    BNSimilarityEntityId entity, BNSimilarityResultId result) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityApplyStatus BNSimilarityProviderApply(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* node,
    BNSimilarityEntityId entity, BNSimilarityResultId result) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityApplyStatus BNSimilaritySessionNodeApplyTarget(
    BNSimilaritySessionNode* node, BNSimilarityEntityId entity,
    const BNSimilarityEntityRef* target) {
  return {};
}
BINARYNINJACOREAPI void BNSimilarityProviderRender(
    BNSimilarityProvider* provider, BNSimilaritySessionNode* node,
    BNSimilarityEntityId entity, BNSimilarityRenderContext* context,
    BNSimilarityResultId result) {}
BINARYNINJACOREAPI BNSimilarityRenderContext* BNCreateSimilarityRenderContext(
    void) {
  return {};
}
BINARYNINJACOREAPI void BNSimilarityRenderContextSetPreferredViewType(
    BNSimilarityRenderContext* context, BNFunctionViewType type) {}
BINARYNINJACOREAPI BNFunctionGraphType
BNSimilarityRenderContextGetPreferredViewType(
    BNSimilarityRenderContext* context) {
  return {};
}
BINARYNINJACOREAPI char* BNSimilarityRenderContextGetPreferredViewTypeName(
    BNSimilarityRenderContext* context) {
  return {};
}
BINARYNINJACOREAPI void BNSimilarityRenderContextAddFlowGraph(
    BNSimilarityRenderContext* context, const char* group, BNFlowGraph* graph) {
}
BINARYNINJACOREAPI void BNSimilarityRenderContextAddFlowGraphForEntity(
    BNSimilarityRenderContext* context, const char* group, BNFlowGraph* graph,
    const BNSimilarityEntityRef* entity) {}
BINARYNINJACOREAPI void BNSimilarityRenderContextAddLinearView(
    BNSimilarityRenderContext* context, const char* group, BNBinaryView* data,
    BNLinearViewObject* linearView) {}
BINARYNINJACOREAPI void BNSimilarityRenderContextAddLinearViewForEntity(
    BNSimilarityRenderContext* context, const char* group, BNBinaryView* data,
    BNLinearViewObject* linearView, const BNSimilarityEntityRef* entity) {}
BINARYNINJACOREAPI BNSimilarityView** BNGetSimilarityRenderContextViews(
    BNSimilarityRenderContext* context, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityViewList(BNSimilarityView** views,
                                                 size_t count) {}
BINARYNINJACOREAPI char* BNSimilarityViewGetGroup(BNSimilarityView* view) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityViewType
BNSimilarityViewGetType(BNSimilarityView* view) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNSimilarityViewGetFlowGraph(
    BNSimilarityView* view) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNSimilarityViewGetLinearViewData(
    BNSimilarityView* view) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNSimilarityViewGetLinearView(
    BNSimilarityView* view) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilarityViewGetEntity(
    BNSimilarityView* view, BNSimilarityEntityRef* entity) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityView* BNNewSimilarityViewReference(
    BNSimilarityView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityView(BNSimilarityView* view) {}
BINARYNINJACOREAPI BNSimilarityRenderContext*
BNNewSimilarityRenderContextReference(BNSimilarityRenderContext* context) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityRenderContext(
    BNSimilarityRenderContext* context) {}
BINARYNINJACOREAPI BNDiffRenderer* BNCreateDiffRenderer(void) { return {}; }
BINARYNINJACOREAPI void BNDiffRendererAddRangeAnnotation(
    BNDiffRenderer* renderer, uint64_t start, uint64_t end,
    BNSimilarityAnnotationType type) {}
BINARYNINJACOREAPI void BNDiffRendererRenderFunction(
    BNDiffRenderer* renderer, BNSimilarityRenderContext* context,
    BNFunction* function) {}
BINARYNINJACOREAPI void BNDiffRendererRenderFunctionForEntity(
    BNDiffRenderer* renderer, BNSimilarityRenderContext* context,
    BNFunction* function, const BNSimilarityEntityRef* entity) {}
BINARYNINJACOREAPI void BNDiffRendererRenderFlowGraph(
    BNDiffRenderer* renderer, BNSimilarityRenderContext* context,
    const char* group, BNFlowGraph* graph) {}
BINARYNINJACOREAPI void BNDiffRendererRenderFlowGraphForEntity(
    BNDiffRenderer* renderer, BNSimilarityRenderContext* context,
    const char* group, BNFlowGraph* graph,
    const BNSimilarityEntityRef* entity) {}
BINARYNINJACOREAPI void BNDiffRendererRenderLinearView(
    BNDiffRenderer* renderer, BNSimilarityRenderContext* context,
    const char* group, BNBinaryView* data, BNLinearViewObject* linearView) {}
BINARYNINJACOREAPI void BNDiffRendererRenderLinearViewForEntity(
    BNDiffRenderer* renderer, BNSimilarityRenderContext* context,
    const char* group, BNBinaryView* data, BNLinearViewObject* linearView,
    const BNSimilarityEntityRef* entity) {}
BINARYNINJACOREAPI BNDiffRenderer* BNNewDiffRendererReference(
    BNDiffRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDiffRenderer(BNDiffRenderer* renderer) {}
BINARYNINJACOREAPI BNSimilarityProvider* BNNewSimilarityProviderReference(
    BNSimilarityProvider* provider) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityProvider(
    BNSimilarityProvider* provider) {}
BINARYNINJACOREAPI void BNFreeSimilarityResultIdList(
    BNSimilarityResultId* results) {}
BINARYNINJACOREAPI BNSimilaritySessionResolverType*
BNRegisterSimilaritySessionResolverType(
    const char* name, const char* description,
    BNCustomSimilaritySessionResolverType* type) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolverType*
BNGetSimilaritySessionResolverTypeByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolverType**
BNGetSimilaritySessionResolverTypeList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionResolverTypeList(
    BNSimilaritySessionResolverType** types) {}
BINARYNINJACOREAPI char* BNSimilaritySessionResolverTypeGetName(
    BNSimilaritySessionResolverType* type) {
  return {};
}
BINARYNINJACOREAPI char* BNSimilaritySessionResolverTypeGetDescription(
    BNSimilaritySessionResolverType* type) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolver*
BNSimilaritySessionResolverTypeCreateResolver(
    BNSimilaritySessionResolverType* type, BNSimilaritySession* session,
    BNSettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNSettings*
BNSimilaritySessionResolverTypeGetDefaultSettings(
    BNSimilaritySessionResolverType* type) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolver*
BNCreateCustomSimilaritySessionResolver(
    BNSimilaritySessionResolverType* type, BNSimilaritySession* session,
    BNCustomSimilaritySessionResolver* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolverType*
BNSimilaritySessionResolverGetType(BNSimilaritySessionResolver* resolver) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolverId
BNSimilaritySessionResolverGetId(BNSimilaritySessionResolver* resolver) {
  return {};
}
BINARYNINJACOREAPI void BNSimilaritySessionResolverPrepareForNode(
    BNSimilaritySessionResolver* resolver, BNSimilaritySession* session,
    BNSimilaritySessionNode* node, BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI void BNSimilaritySessionResolverResolveForNode(
    BNSimilaritySessionResolver* resolver, BNSimilaritySession* session,
    BNSimilaritySessionNode* node, const BNSimilarityEntityId* entities,
    size_t entityCount, BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI BNSimilaritySessionResolver*
BNNewSimilaritySessionResolverReference(BNSimilaritySessionResolver* resolver) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionResolver(
    BNSimilaritySessionResolver* resolver) {}
BINARYNINJACOREAPI void BNFreeSimilaritySessionResolverList(
    BNSimilaritySessionResolver** resolvers, size_t count) {}
BINARYNINJACOREAPI BNSimilaritySessionNode* BNCreateSimilaritySessionNode(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNode*
BNCreateSimilaritySessionNodeFromFile(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNSimilaritySessionNodeGetView(
    BNSimilaritySessionNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNSimilaritySessionNodeSetView(
    BNSimilaritySessionNode* node, BNBinaryView* view) {}
BINARYNINJACOREAPI BNFileMetadata* BNSimilaritySessionNodeGetFile(
    BNSimilaritySessionNode* node) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNSimilaritySessionNodeGetLoadOptions(
    BNSimilaritySessionNode* node) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNodeId
BNSimilaritySessionNodeGetId(BNSimilaritySessionNode* node) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityEntityId BNSimilaritySessionNodeCreateEntity(
    BNSimilaritySessionNode* node, const BNSimilarityEntityInfo* info) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeRemoveEntity(
    BNSimilaritySessionNode* node, BNSimilarityEntityId id) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeGetEntity(
    BNSimilaritySessionNode* node, BNSimilarityEntityId id,
    BNSimilarityEntityInfo* result) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityEntityInfo(
    BNSimilarityEntityInfo* info) {}
BINARYNINJACOREAPI BNSimilarityEntityId* BNSimilaritySessionNodeGetEntities(
    BNSimilaritySessionNode* node, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeAddScheduledEntity(
    BNSimilaritySessionNode* node, BNSimilarityEntityId id) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeRemoveScheduledEntity(
    BNSimilaritySessionNode* node, BNSimilarityEntityId id) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityEntityId*
BNSimilaritySessionNodeGetScheduledEntities(BNSimilaritySessionNode* node,
                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNSimilaritySessionNodeGetEntityFunction(
    BNSimilaritySessionNode* node, BNSimilarityEntityId id) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityResultId* BNSimilaritySessionNodeGetResults(
    BNSimilaritySessionNode* node, BNSimilarityEntityId entity, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeGetResult(
    BNSimilaritySessionNode* node, BNSimilarityResultId resultId,
    BNSimilarityResult* result) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeSetResolvedResult(
    BNSimilaritySessionNode* node, BNSimilarityEntityId entity,
    BNSimilarityResultId result) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeGetResolvedResult(
    BNSimilaritySessionNode* node, BNSimilarityEntityId entity,
    BNSimilarityResultId* result) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionNodeClearResolvedResult(
    BNSimilaritySessionNode* node, BNSimilarityEntityId entity) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityEntityList(
    BNSimilarityEntityId* entities) {}
BINARYNINJACOREAPI BNSimilaritySessionNodeId*
BNSimilaritySessionNodeGetIncomingEdges(BNSimilaritySessionNode* node,
                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNodeId*
BNSimilaritySessionNodeGetOutgoingEdges(BNSimilaritySessionNode* node,
                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionNodeEdgeList(
    BNSimilaritySessionNodeId* edges) {}
BINARYNINJACOREAPI BNSimilaritySessionNode**
BNSimilaritySessionNodeGetIncomingNodes(BNSimilaritySessionNode* node,
                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNode**
BNSimilaritySessionNodeGetOutgoingNodes(BNSimilaritySessionNode* node,
                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNode* BNNewSimilaritySessionNodeReference(
    BNSimilaritySessionNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionNode(
    BNSimilaritySessionNode* node) {}
BINARYNINJACOREAPI void BNSimilaritySessionGraphAddNode(
    BNSimilaritySessionGraph* graph, BNSimilaritySessionNode* node) {}
BINARYNINJACOREAPI void BNSimilaritySessionGraphRemoveNode(
    BNSimilaritySessionGraph* graph, BNSimilaritySessionNode* node) {}
BINARYNINJACOREAPI bool BNSimilaritySessionGraphIsValidEdge(
    BNSimilaritySessionGraph* graph, BNSimilaritySessionNode* from,
    BNSimilaritySessionNode* to) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionGraphAddEdge(
    BNSimilaritySessionGraph* graph, BNSimilaritySessionNode* from,
    BNSimilaritySessionNode* to) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionGraphRemoveEdge(
    BNSimilaritySessionGraph* graph, BNSimilaritySessionNode* from,
    BNSimilaritySessionNode* to) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNode* BNSimilaritySessionGraphGetNode(
    BNSimilaritySessionGraph* graph, BNSimilaritySessionNodeId id) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionNode** BNSimilaritySessionGraphGetNodes(
    BNSimilaritySessionGraph* graph, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionNodeList(
    BNSimilaritySessionNode** nodes, size_t count) {}
BINARYNINJACOREAPI BNSimilaritySessionNode***
BNSimilaritySessionGraphGetSchedule(BNSimilaritySessionGraph* graph,
                                    size_t** nodeCounts, size_t* levelCount) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionNodeSchedule(
    BNSimilaritySessionNode*** schedule, size_t* nodeCounts,
    size_t levelCount) {}
BINARYNINJACOREAPI BNSimilaritySessionGraph*
BNNewSimilaritySessionGraphReference(BNSimilaritySessionGraph* node) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionGraph(
    BNSimilaritySessionGraph* graph) {}
BINARYNINJACOREAPI BNSimilaritySessionGraphReceiver*
BNCreateCustomSimilaritySessionGraphReceiver(
    BNCustomSimilaritySessionGraphReceiver* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionGraphReceiver*
BNNewSimilaritySessionGraphReceiverReference(
    BNSimilaritySessionGraphReceiver* receiver) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionGraphReceiver(
    BNSimilaritySessionGraphReceiver* receiver) {}
BINARYNINJACOREAPI void BNFreeSimilaritySessionGraphReceiverList(
    BNSimilaritySessionGraphReceiver** receivers, size_t count) {}
BINARYNINJACOREAPI void BNSimilaritySessionGraphReceiverNotifyGraphChanged(
    BNSimilaritySessionGraphReceiver* receiver) {}
BINARYNINJACOREAPI void BNSimilaritySessionGraphAddReceiver(
    BNSimilaritySessionGraph* graph,
    BNSimilaritySessionGraphReceiver* receiver) {}
BINARYNINJACOREAPI void BNSimilaritySessionGraphRemoveReceiver(
    BNSimilaritySessionGraph* graph,
    BNSimilaritySessionGraphReceiver* receiver) {}
BINARYNINJACOREAPI BNSimilaritySessionGraphReceiver**
BNSimilaritySessionGraphGetReceivers(BNSimilaritySessionGraph* graph,
                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySession* BNCreateSimilaritySession() {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionId
BNSimilaritySessionGetId(BNSimilaritySession* session) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionReceiver*
BNCreateCustomSimilaritySessionReceiver(
    BNCustomSimilaritySessionReceiver* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionReceiver*
BNNewSimilaritySessionReceiverReference(BNSimilaritySessionReceiver* receiver) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionReceiver(
    BNSimilaritySessionReceiver* receiver) {}
BINARYNINJACOREAPI void BNFreeSimilaritySessionReceiverList(
    BNSimilaritySessionReceiver** receivers, size_t count) {}
BINARYNINJACOREAPI void BNSimilaritySessionReceiverNotifyStart(
    BNSimilaritySessionReceiver* receiver,
    BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI void BNSimilaritySessionReceiverNotifyBatch(
    BNSimilaritySessionReceiver* receiver, BNSimilaritySessionNode* node,
    BNSimilarityProvider* provider, const BNSimilarityEntityId* entities,
    size_t count) {}
BINARYNINJACOREAPI void BNSimilaritySessionAddProvider(
    BNSimilaritySession* session, BNSimilarityProvider* provider) {}
BINARYNINJACOREAPI void BNSimilaritySessionRemoveProvider(
    BNSimilaritySession* session, BNSimilarityProvider* provider) {}
BINARYNINJACOREAPI bool BNSimilaritySessionUpdateProviderSettings(
    BNSimilaritySession* session, BNSimilarityProvider* provider,
    BNSettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProvider* BNSimilaritySessionGetProvider(
    BNSimilaritySession* session, BNSimilarityProviderId id) {
  return {};
}
BINARYNINJACOREAPI BNSimilarityProvider** BNSimilaritySessionGetProviders(
    BNSimilaritySession* session, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilarityProviderList(
    BNSimilarityProvider** providers, size_t count) {}
BINARYNINJACOREAPI bool BNSimilaritySessionAddResolver(
    BNSimilaritySession* session, BNSimilaritySessionResolver* resolver) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionRemoveResolver(
    BNSimilaritySession* session, BNSimilaritySessionResolver* resolver) {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionUpdateResolverSettings(
    BNSimilaritySession* session, BNSimilaritySessionResolver* resolver,
    BNSettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolver* BNSimilaritySessionGetResolver(
    BNSimilaritySession* session, BNSimilaritySessionResolverId id) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionResolver**
BNSimilaritySessionGetResolvers(BNSimilaritySession* session, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSimilaritySessionAddReceiver(
    BNSimilaritySession* session, BNSimilaritySessionReceiver* receiver) {}
BINARYNINJACOREAPI void BNSimilaritySessionRemoveReceiver(
    BNSimilaritySession* session, BNSimilaritySessionReceiver* receiver) {}
BINARYNINJACOREAPI BNSimilaritySessionReceiver**
BNSimilaritySessionGetReceivers(BNSimilaritySession* session, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionGraph* BNSimilaritySessionGetGraph(
    BNSimilaritySession* session) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionCompletion* BNSimilaritySessionRun(
    BNSimilaritySession* session) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySession* BNNewSimilaritySessionReference(
    BNSimilaritySession* session) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySession(BNSimilaritySession* session) {}
BINARYNINJACOREAPI BNSimilaritySessionCompletion*
BNCreateSimilaritySessionCompletion() {
  return {};
}
BINARYNINJACOREAPI bool BNSimilaritySessionCompletionIsFinished(
    BNSimilaritySessionCompletion* completion) {
  return {};
}
BINARYNINJACOREAPI void BNSimilaritySessionCompletionRequestStop(
    BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI bool BNSimilaritySessionCompletionIsStopRequested(
    BNSimilaritySessionCompletion* completion) {
  return {};
}
BINARYNINJACOREAPI double BNSimilaritySessionCompletionGetProgress(
    BNSimilaritySessionCompletion* completion,
    const BNSimilaritySessionCompletionQuery* query) {
  return {};
}
BINARYNINJACOREAPI void BNSimilaritySessionCompletionSetProgress(
    BNSimilaritySessionCompletion* completion,
    const BNSimilaritySessionCompletionQuery* query, double progress) {}
BINARYNINJACOREAPI uint64_t BNSimilaritySessionCompletionGetTiming(
    BNSimilaritySessionCompletion* completion,
    const BNSimilaritySessionCompletionQuery* query) {
  return {};
}
BINARYNINJACOREAPI BNSimilaritySessionCompletion*
BNNewSimilaritySessionCompletionReference(
    BNSimilaritySessionCompletion* completion) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSimilaritySessionCompletion(
    BNSimilaritySessionCompletion* completion) {}
BINARYNINJACOREAPI char* BNAllocString(const char* contents) { return {}; }
BINARYNINJACOREAPI char* BNAllocStringWithLength(const char* contents,
                                                 size_t len) {
  return {};
}
BINARYNINJACOREAPI void BNFreeString(char* str) {}
BINARYNINJACOREAPI char** BNAllocStringList(const char** contents,
                                            size_t size) {
  return {};
}
BINARYNINJACOREAPI char** BNAllocUninitializedStringList(size_t size) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStringList(char** strs, size_t count) {}
BINARYNINJACOREAPI void BNShutdown(void) {}
BINARYNINJACOREAPI bool BNIsShutdownRequested(void) { return {}; }
BINARYNINJACOREAPI int BNRunUnitTests(int argc, char** argv) { return {}; }
BINARYNINJACOREAPI BNVersionInfo BNGetVersionInfo(void) { return {}; }
BINARYNINJACOREAPI char* BNGetVersionString(void) { return {}; }
BINARYNINJACOREAPI uint32_t BNGetBuildId(void) { return {}; }
BINARYNINJACOREAPI uint32_t BNGetCurrentCoreABIVersion(void) { return {}; }
BINARYNINJACOREAPI uint32_t BNGetMinimumCoreABIVersion(void) { return {}; }
BINARYNINJACOREAPI char* BNGetSerialNumber(void) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetLicenseExpirationTime(void) { return {}; }
BINARYNINJACOREAPI bool BNIsLicenseValidated(void) { return {}; }
BINARYNINJACOREAPI char* BNGetLicensedUserEmail(void) { return {}; }
BINARYNINJACOREAPI char* BNGetProduct(void) { return {}; }
BINARYNINJACOREAPI char* BNGetProductType(void) { return {}; }
BINARYNINJACOREAPI BNLicenseAddon* BNGetLicenseAddons(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLicenseAddons(BNLicenseAddon* addons,
                                            size_t count) {}
BINARYNINJACOREAPI int BNGetLicenseCount(void) { return {}; }
BINARYNINJACOREAPI bool BNIsUIEnabled(void) { return {}; }
BINARYNINJACOREAPI void BNSetLicense(const char* licenseData) {}
BINARYNINJACOREAPI bool BNIsDatabase(const char* filename) { return {}; }
BINARYNINJACOREAPI bool BNIsDatabaseFromData(const void* data, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNAuthenticateEnterpriseServerWithToken(
    const char* token, bool remember) {
  return {};
}
BINARYNINJACOREAPI bool BNAuthenticateEnterpriseServerWithCredentials(
    const char* username, const char* password, bool remember) {
  return {};
}
BINARYNINJACOREAPI bool BNAuthenticateEnterpriseServerWithMethod(
    const char* method, bool remember) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetEnterpriseServerAuthenticationMethods(char*** methods, char*** names) {
  return {};
}
BINARYNINJACOREAPI bool BNDeauthenticateEnterpriseServer(void) { return {}; }
BINARYNINJACOREAPI void BNCancelEnterpriseServerAuthentication(void) {}
BINARYNINJACOREAPI bool BNConnectEnterpriseServer(void) { return {}; }
BINARYNINJACOREAPI bool BNUpdateEnterpriseServerLicense(uint64_t timeout) {
  return {};
}
BINARYNINJACOREAPI bool BNReleaseEnterpriseServerLicense(void) { return {}; }
BINARYNINJACOREAPI bool BNIsEnterpriseServerConnected(void) { return {}; }
BINARYNINJACOREAPI bool BNIsEnterpriseServerAuthenticated(void) { return {}; }
BINARYNINJACOREAPI char* BNGetEnterpriseServerUsername(void) { return {}; }
BINARYNINJACOREAPI char* BNGetEnterpriseServerToken(void) { return {}; }
BINARYNINJACOREAPI char* BNGetEnterpriseServerUrl(void) { return {}; }
BINARYNINJACOREAPI bool BNSetEnterpriseServerUrl(const char* url) { return {}; }
BINARYNINJACOREAPI char* BNGetEnterpriseServerName(void) { return {}; }
BINARYNINJACOREAPI char* BNGetEnterpriseServerId(void) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetEnterpriseServerVersion(void) { return {}; }
BINARYNINJACOREAPI char* BNGetEnterpriseServerBuildId(void) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetEnterpriseServerLicenseExpirationTime(void) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetEnterpriseServerLicenseDuration(void) {
  return {};
}
BINARYNINJACOREAPI bool BNIsEnterpriseServerFloatingLicense(void) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetEnterpriseServerReservationTimeLimit(void) {
  return {};
}
BINARYNINJACOREAPI bool BNIsEnterpriseServerLicenseStillActivated(void) {
  return {};
}
BINARYNINJACOREAPI char* BNGetEnterpriseServerLastError(void) { return {}; }
BINARYNINJACOREAPI void BNRegisterEnterpriseServerNotification(
    BNEnterpriseServerCallbacks* notify) {}
BINARYNINJACOREAPI void BNUnregisterEnterpriseServerNotification(
    BNEnterpriseServerCallbacks* notify) {}
BINARYNINJACOREAPI bool BNIsEnterpriseServerInitialized(void) { return {}; }
BINARYNINJACOREAPI bool BNInitializeEnterpriseServer(void) { return {}; }
BINARYNINJACOREAPI void BNRegisterObjectDestructionCallbacks(
    BNObjectDestructionCallbacks* callbacks) {}
BINARYNINJACOREAPI void BNUnregisterObjectDestructionCallbacks(
    BNObjectDestructionCallbacks* callbacks) {}
BINARYNINJACOREAPI char* BNGetUniqueIdentifierString(void) { return {}; }
BINARYNINJACOREAPI bool BNInitPlugins(bool allowUserPlugins) { return {}; }
BINARYNINJACOREAPI void BNDisablePlugins(void) {}
BINARYNINJACOREAPI bool BNIsPluginsEnabled(void) { return {}; }
BINARYNINJACOREAPI char* BNGetInstallDirectory(void) { return {}; }
BINARYNINJACOREAPI char* BNGetBundledPluginDirectory(void) { return {}; }
BINARYNINJACOREAPI char* BNGetBundledScriptPluginDirectory(void) { return {}; }
BINARYNINJACOREAPI void BNSetBundledPluginDirectory(const char* path) {}
BINARYNINJACOREAPI void BNSetBundledScriptPluginDirectory(const char* path) {}
BINARYNINJACOREAPI char* BNGetUserDirectory(void) { return {}; }
BINARYNINJACOREAPI char* BNGetUserPluginDirectory(void) { return {}; }
BINARYNINJACOREAPI char* BNGetRepositoriesDirectory(void) { return {}; }
BINARYNINJACOREAPI char* BNGetSettingsFileName(void) { return {}; }
BINARYNINJACOREAPI void BNSaveLastRun(void) {}
BINARYNINJACOREAPI char* BNGetPathRelativeToBundledPluginDirectory(
    const char* path) {
  return {};
}
BINARYNINJACOREAPI char* BNGetPathRelativeToUserPluginDirectory(
    const char* path) {
  return {};
}
BINARYNINJACOREAPI char* BNGetPathRelativeToUserDirectory(const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNExecuteWorkerProcess(
    const char* path, const char** args, BNDataBuffer* input, char** output,
    char** error, bool stdoutIsText, bool stderrIsText) {
  return {};
}
BINARYNINJACOREAPI void BNSetCurrentPluginLoadOrder(BNPluginLoadPhase order) {}
BINARYNINJACOREAPI void BNAddRequiredPluginDependency(const char* name) {}
BINARYNINJACOREAPI void BNAddOptionalPluginDependency(const char* name) {}
BINARYNINJACOREAPI void BNLog(size_t session, BNLogLevel level,
                              const char* logger_name, size_t tid,
                              const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogDebug(const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogInfo(const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogWarn(const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogError(const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogAlert(const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogString(size_t session, BNLogLevel level,
                                    const char* logger_name, size_t tid,
                                    const char* str) {}
BINARYNINJACOREAPI void BNLogWithStackTrace(size_t session, BNLogLevel level,
                                            const char* logger_name, size_t tid,
                                            const char* stackTrace,
                                            const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogDebugWithStackTrace(const char* stackTrace,
                                                 const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogInfoWithStackTrace(const char* stackTrace,
                                                const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogWarnWithStackTrace(const char* stackTrace,
                                                const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogErrorWithStackTrace(const char* stackTrace,
                                                 const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogAlertWithStackTrace(const char* stackTrace,
                                                 const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLogStringWithStackTrace(
    size_t session, BNLogLevel level, const char* logger_name, size_t tid,
    const char* stackTrace, const char* str) {}
BINARYNINJACOREAPI BNLogger* BNNewLoggerReference(BNLogger* logger) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLogger(BNLogger* logger) {}
BINARYNINJACOREAPI void BNLoggerLog(BNLogger* logger, BNLogLevel level,
                                    const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLoggerLogString(BNLogger* logger, BNLogLevel level,
                                          const char* msg) {}
BINARYNINJACOREAPI void BNLoggerLogWithStackTrace(BNLogger* logger,
                                                  BNLogLevel level,
                                                  const char* stackTrace,
                                                  const char* fmt, ...) {}
BINARYNINJACOREAPI void BNLoggerLogStringWithStackTrace(BNLogger* logger,
                                                        BNLogLevel level,
                                                        const char* stackTrace,
                                                        const char* msg) {}
BINARYNINJACOREAPI char* BNLoggerGetName(BNLogger* logger) { return {}; }
BINARYNINJACOREAPI size_t BNLoggerGetSessionId(BNLogger* logger) { return {}; }
BINARYNINJACOREAPI BNLogger* BNLogCreateLogger(const char* loggerName,
                                               size_t sessionId) {
  return {};
}
BINARYNINJACOREAPI BNLogger* BNLogGetLogger(const char* loggerName,
                                            size_t sessionId) {
  return {};
}
BINARYNINJACOREAPI char** BNLogGetLoggerNames(size_t* count) { return {}; }
BINARYNINJACOREAPI void BNRegisterLogListener(BNLogListener* listener) {}
BINARYNINJACOREAPI void BNUnregisterLogListener(BNLogListener* listener) {}
BINARYNINJACOREAPI void BNUpdateLogListeners(void) {}
BINARYNINJACOREAPI void BNLogToStdout(BNLogLevel minimumLevel) {}
BINARYNINJACOREAPI void BNLogToStderr(BNLogLevel minimumLevel) {}
BINARYNINJACOREAPI bool BNLogToFile(BNLogLevel minimumLevel, const char* path,
                                    bool append) {
  return {};
}
BINARYNINJACOREAPI void BNCloseLogs(void) {}
BINARYNINJACOREAPI BNTemporaryFile* BNCreateTemporaryFile(void) { return {}; }
BINARYNINJACOREAPI BNTemporaryFile* BNCreateTemporaryFileWithContents(
    BNDataBuffer* data) {
  return {};
}
BINARYNINJACOREAPI BNTemporaryFile* BNNewTemporaryFileReference(
    BNTemporaryFile* file) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTemporaryFile(BNTemporaryFile* file) {}
BINARYNINJACOREAPI char* BNGetTemporaryFilePath(BNTemporaryFile* file) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetTemporaryFileContents(
    BNTemporaryFile* file) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNCreateDataBuffer(const void* data,
                                                    size_t len) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNDuplicateDataBuffer(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDataBuffer(BNDataBuffer* buf) {}
BINARYNINJACOREAPI void* BNGetDataBufferContents(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI void* BNGetDataBufferContentsAt(BNDataBuffer* buf,
                                                   size_t offset) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetDataBufferLength(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetDataBufferSlice(BNDataBuffer* buf,
                                                      size_t start,
                                                      size_t len) {
  return {};
}
BINARYNINJACOREAPI void BNSetDataBufferLength(BNDataBuffer* buf, size_t len) {}
BINARYNINJACOREAPI void BNClearDataBuffer(BNDataBuffer* buf) {}
BINARYNINJACOREAPI void BNSetDataBufferContents(BNDataBuffer* buf, void* data,
                                                size_t len) {}
BINARYNINJACOREAPI void BNAssignDataBuffer(BNDataBuffer* dest,
                                           BNDataBuffer* src) {}
BINARYNINJACOREAPI void BNAppendDataBuffer(BNDataBuffer* dest,
                                           BNDataBuffer* src) {}
BINARYNINJACOREAPI void BNAppendDataBufferContents(BNDataBuffer* dest,
                                                   const void* src,
                                                   size_t len) {}
BINARYNINJACOREAPI uint8_t BNGetDataBufferByte(BNDataBuffer* buf,
                                               size_t offset) {
  return {};
}
BINARYNINJACOREAPI void BNSetDataBufferByte(BNDataBuffer* buf, size_t offset,
                                            uint8_t val) {}
BINARYNINJACOREAPI char* BNDataBufferToEscapedString(BNDataBuffer* buf,
                                                     bool nullTerminates,
                                                     bool escapePrintable) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNDecodeEscapedString(const char* str) {
  return {};
}
BINARYNINJACOREAPI char* BNDataBufferToBase64(BNDataBuffer* buf) { return {}; }
BINARYNINJACOREAPI BNDataBuffer* BNDecodeBase64(const char* str) { return {}; }
BINARYNINJACOREAPI BNDataBuffer* BNZlibCompress(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNZlibDecompress(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNLzmaDecompress(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNLzma2Decompress(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNXzDecompress(BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNSaveSettings* BNCreateSaveSettings(void) { return {}; }
BINARYNINJACOREAPI BNSaveSettings* BNNewSaveSettingsReference(
    BNSaveSettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSaveSettings(BNSaveSettings* settings) {}
BINARYNINJACOREAPI bool BNIsSaveSettingsOptionSet(BNSaveSettings* settings,
                                                  BNSaveOption option) {
  return {};
}
BINARYNINJACOREAPI void BNSetSaveSettingsOption(BNSaveSettings* settings,
                                                BNSaveOption option,
                                                bool state) {}
BINARYNINJACOREAPI char* BNGetSaveSettingsName(BNSaveSettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetSaveSettingsName(BNSaveSettings* settings,
                                              const char* name) {}
BINARYNINJACOREAPI BNFileMetadata* BNCreateFileMetadata() { return {}; }
BINARYNINJACOREAPI BNFileMetadata* BNNewFileReference(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFileMetadata(BNFileMetadata* file) {}
BINARYNINJACOREAPI void BNCloseFile(BNFileMetadata* file) {}
BINARYNINJACOREAPI void BNSetFileMetadataNavigationHandler(
    BNFileMetadata* file, BNNavigationHandler* handler) {}
BINARYNINJACOREAPI bool BNIsFileModified(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI bool BNIsAnalysisChanged(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI void BNMarkFileModified(BNFileMetadata* file) {}
BINARYNINJACOREAPI void BNMarkFileSaved(BNFileMetadata* file) {}
BINARYNINJACOREAPI bool BNIsBackedByDatabase(BNFileMetadata* file,
                                             const char* binaryViewType) {
  return {};
}
BINARYNINJACOREAPI bool BNCreateDatabase(BNBinaryView* data, const char* path,
                                         BNSaveSettings* settings) {
  return {};
}
BINARYNINJACOREAPI bool BNCreateDatabaseWithProgress(
    BNBinaryView* data, const char* path, void* ctxt,
    BNProgressFunction progress, BNSaveSettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNOpenExistingDatabase(BNFileMetadata* file,
                                                        const char* path) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNOpenExistingDatabaseWithProgress(
    BNFileMetadata* file, const char* path, void* ctxt,
    BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNOpenDatabaseForConfiguration(
    BNFileMetadata* file, const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNReopenMovedDatabase(BNFileMetadata* file,
                                              const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNSaveAutoSnapshot(BNBinaryView* data,
                                           BNSaveSettings* settings) {
  return {};
}
BINARYNINJACOREAPI bool BNSaveAutoSnapshotWithProgress(
    BNBinaryView* data, void* ctxt, BNProgressFunction progress,
    BNSaveSettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNGetSnapshotData(BNFileMetadata* file,
                                          BNKeyValueStore* data,
                                          BNKeyValueStore* cache, void* ctxt,
                                          BNProgressFunction progress) {}
BINARYNINJACOREAPI void BNApplySnapshotData(
    BNFileMetadata* file, BNBinaryView* view, BNKeyValueStore* data,
    BNKeyValueStore* cache, void* ctxt, BNProgressFunction progress,
    bool openForConfiguration, bool restoreRawView) {}
BINARYNINJACOREAPI BNDatabase* BNGetFileMetadataDatabase(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI BNKeyValueStore* BNCreateKeyValueStore(void) { return {}; }
BINARYNINJACOREAPI BNKeyValueStore* BNCreateKeyValueStoreFromDataBuffer(
    BNDataBuffer* buffer) {
  return {};
}
BINARYNINJACOREAPI BNKeyValueStore* BNNewKeyValueStoreReference(
    BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI void BNFreeKeyValueStore(BNKeyValueStore* store) {}
BINARYNINJACOREAPI char** BNGetKeyValueStoreKeys(BNKeyValueStore* store,
                                                 size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNKeyValueStoreHasValue(BNKeyValueStore* store,
                                                const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetKeyValueStoreValue(BNKeyValueStore* store,
                                                 const char* name) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetKeyValueStoreValueHash(
    BNKeyValueStore* store, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetKeyValueStoreBuffer(
    BNKeyValueStore* store, const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNSetKeyValueStoreValue(BNKeyValueStore* store,
                                                const char* name,
                                                const char* value) {
  return {};
}
BINARYNINJACOREAPI bool BNSetKeyValueStoreBuffer(BNKeyValueStore* store,
                                                 const char* name,
                                                 const BNDataBuffer* value) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetKeyValueStoreSerializedData(
    BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI void BNBeginKeyValueStoreNamespace(BNKeyValueStore* store,
                                                      const char* name) {}
BINARYNINJACOREAPI void BNEndKeyValueStoreNamespace(BNKeyValueStore* store) {}
BINARYNINJACOREAPI bool BNIsKeyValueStoreEmpty(BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetKeyValueStoreValueSize(BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetKeyValueStoreDataSize(BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetKeyValueStoreValueStorageSize(BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetKeyValueStoreNamespaceSize(BNKeyValueStore* store) {
  return {};
}
BINARYNINJACOREAPI BNProject* BNNewProjectReference(BNProject* project) {
  return {};
}
BINARYNINJACOREAPI void BNFreeProject(BNProject* project) {}
BINARYNINJACOREAPI void BNFreeProjectList(BNProject** projects, size_t count) {}
BINARYNINJACOREAPI BNProject** BNGetOpenProjects(size_t* count) { return {}; }
BINARYNINJACOREAPI BNProject* BNCreateProject(const char* path,
                                              const char* name) {
  return {};
}
BINARYNINJACOREAPI BNProject* BNOpenProject(const char* path) { return {}; }
BINARYNINJACOREAPI bool BNProjectOpen(BNProject* project) { return {}; }
BINARYNINJACOREAPI bool BNProjectClose(BNProject* project) { return {}; }
BINARYNINJACOREAPI char* BNProjectGetId(BNProject* project) { return {}; }
BINARYNINJACOREAPI bool BNProjectIsOpen(BNProject* project) { return {}; }
BINARYNINJACOREAPI char* BNProjectGetPath(BNProject* project) { return {}; }
BINARYNINJACOREAPI char* BNProjectGetFilePathInProject(BNProject* project,
                                                       BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectGetName(BNProject* project) { return {}; }
BINARYNINJACOREAPI bool BNProjectSetName(BNProject* project, const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectGetDescription(BNProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectSetDescription(BNProject* project,
                                                const char* description) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNProjectQueryMetadata(BNProject* project,
                                                      const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectStoreMetadata(BNProject* project,
                                               const char* key,
                                               BNMetadata* value) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectRemoveMetadata(BNProject* project,
                                                const char* key) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNProjectCreateFileFromPath(
    BNProject* project, const char* path, BNProjectFolder* folder,
    const char* name, const char* description, void* ctxt,
    BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNProjectCreateFileFromPathUnsafe(
    BNProject* project, const char* path, BNProjectFolder* folder,
    const char* name, const char* description, const char* id,
    int64_t creationTimestamp, void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNProjectCreateFile(
    BNProject* project, const uint8_t* contents, size_t contentsSize,
    BNProjectFolder* folder, const char* name, const char* description,
    void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNProjectCreateFileUnsafe(
    BNProject* project, const uint8_t* contents, size_t contentsSize,
    BNProjectFolder* folder, const char* name, const char* description,
    const char* id, int64_t creationTimestamp, void* ctxt,
    BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile** BNProjectGetFiles(BNProject* project,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNProjectGetFileById(BNProject* project,
                                                       const char* id) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNProjectGetFileByPathOnDisk(
    BNProject* project, const char* path) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile** BNProjectGetFilesByPathInProject(
    BNProject* project, const char* path, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile** BNProjectGetFilesInFolder(
    BNProject* project, BNProjectFolder* folder, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectPushFile(BNProject* project,
                                          BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectDeleteFile(BNProject* project,
                                            BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder* BNProjectCreateFolderFromPath(
    BNProject* project, const char* path, BNProjectFolder* parent,
    const char* description, void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder* BNProjectCreateFolder(
    BNProject* project, BNProjectFolder* parent, const char* name,
    const char* description) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder* BNProjectCreateFolderUnsafe(
    BNProject* project, BNProjectFolder* parent, const char* name,
    const char* description, const char* id) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder** BNProjectGetFolders(BNProject* project,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder* BNProjectGetFolderById(BNProject* project,
                                                           const char* id) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectPushFolder(BNProject* project,
                                            BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectDeleteFolder(BNProject* project,
                                              BNProjectFolder* folder,
                                              void* ctxt,
                                              BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectBeginBulkOperation(BNProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectEndBulkOperation(BNProject* project) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNProjectGetRemoteProject(
    BNProject* project) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile* BNNewProjectFileReference(
    BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI void BNFreeProjectFile(BNProjectFile* file) {}
BINARYNINJACOREAPI void BNFreeProjectFileList(BNProjectFile** files,
                                              size_t count) {}
BINARYNINJACOREAPI char* BNProjectFileGetPathOnDisk(BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectFileGetPathInProject(
    const BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileExistsOnDisk(BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectFileGetName(BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileSetName(BNProjectFile* file,
                                             const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectFileGetDescription(BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileSetDescription(BNProjectFile* file,
                                                    const char* description) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectFileGetId(BNProjectFile* file) { return {}; }
BINARYNINJACOREAPI BNProjectFolder* BNProjectFileGetFolder(
    BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileSetFolder(BNProjectFile* file,
                                               BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI BNProject* BNProjectFileGetProject(BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileExport(BNProjectFile* file,
                                            const char* destination) {
  return {};
}
BINARYNINJACOREAPI int64_t
BNProjectFileGetCreationTimestamp(BNProjectFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileAddDependency(BNProjectFile* file,
                                                   BNProjectFile* dep) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFileRemoveDependency(BNProjectFile* file,
                                                      BNProjectFile* dep) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile** BNProjectFileGetDependencies(
    BNProjectFile* file, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile** BNProjectFileGetRequiredBy(
    BNProjectFile* file, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder* BNNewProjectFolderReference(
    BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI void BNFreeProjectFolder(BNProjectFolder* folder) {}
BINARYNINJACOREAPI void BNFreeProjectFolderList(BNProjectFolder** folders,
                                                size_t count) {}
BINARYNINJACOREAPI char* BNProjectFolderGetId(BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectFolderGetName(BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFolderSetName(BNProjectFolder* folder,
                                               const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNProjectFolderGetDescription(
    BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFolderSetDescription(BNProjectFolder* folder,
                                                      const char* description) {
  return {};
}
BINARYNINJACOREAPI BNProjectFolder* BNProjectFolderGetParent(
    BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFolderSetParent(BNProjectFolder* folder,
                                                 BNProjectFolder* parent) {
  return {};
}
BINARYNINJACOREAPI BNProject* BNProjectFolderGetProject(
    BNProjectFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNProjectFolderExport(BNProjectFolder* folder,
                                              const char* destination,
                                              void* ctxt,
                                              BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile** BNProjectFolderGetFiles(
    BNProjectFolder* folder, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNExternalLibrary* BNNewExternalLibraryReference(
    BNExternalLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI void BNFreeExternalLibrary(BNExternalLibrary* lib) {}
BINARYNINJACOREAPI void BNFreeExternalLibraryList(BNExternalLibrary** libs,
                                                  size_t count) {}
BINARYNINJACOREAPI char* BNExternalLibraryGetName(BNExternalLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI void BNExternalLibrarySetBackingFile(BNExternalLibrary* lib,
                                                        BNProjectFile* file) {}
BINARYNINJACOREAPI BNProjectFile* BNExternalLibraryGetBackingFile(
    BNExternalLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI BNExternalLocation* BNNewExternalLocationReference(
    BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI void BNFreeExternalLocation(BNExternalLocation* loc) {}
BINARYNINJACOREAPI void BNFreeExternalLocationList(BNExternalLocation** locs,
                                                   size_t count) {}
BINARYNINJACOREAPI BNSymbol* BNExternalLocationGetSourceSymbol(
    BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNExternalLocationGetTargetAddress(BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI char* BNExternalLocationGetTargetSymbol(
    BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI BNExternalLibrary* BNExternalLocationGetExternalLibrary(
    BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI bool BNExternalLocationHasTargetAddress(
    BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI bool BNExternalLocationHasTargetSymbol(
    BNExternalLocation* loc) {
  return {};
}
BINARYNINJACOREAPI bool BNExternalLocationSetTargetAddress(
    BNExternalLocation* loc, uint64_t* address) {
  return {};
}
BINARYNINJACOREAPI bool BNExternalLocationSetTargetSymbol(
    BNExternalLocation* loc, const char* symbol) {
  return {};
}
BINARYNINJACOREAPI void BNExternalLocationSetExternalLibrary(
    BNExternalLocation* loc, BNExternalLibrary* library) {}
BINARYNINJACOREAPI BNDatabase* BNNewDatabaseReference(BNDatabase* database) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDatabase(BNDatabase* database) {}
BINARYNINJACOREAPI BNDatabase* BNCreateDatabaseInstance(void) { return {}; }
BINARYNINJACOREAPI bool BNDatabaseOpenExisting(BNDatabase* database,
                                               const char* path) {
  return {};
}
BINARYNINJACOREAPI void BNSetDatabaseCurrentSnapshot(BNDatabase* database,
                                                     int64_t id) {}
BINARYNINJACOREAPI BNSnapshot* BNGetDatabaseCurrentSnapshot(
    BNDatabase* database) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot** BNGetDatabaseSnapshots(BNDatabase* database,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot* BNGetDatabaseSnapshot(BNDatabase* database,
                                                     int64_t id) {
  return {};
}
BINARYNINJACOREAPI int64_t BNWriteDatabaseSnapshotData(
    BNDatabase* database, int64_t* parents, size_t parentCount,
    BNBinaryView* file, const char* name, BNKeyValueStore* data, bool autoSave,
    void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI bool BNTrimDatabaseSnapshot(BNDatabase* database,
                                               int64_t id) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDatabaseSnapshot(BNDatabase* database,
                                                 int64_t id) {
  return {};
}
BINARYNINJACOREAPI char** BNGetDatabaseGlobalKeys(BNDatabase* database,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI int BNDatabaseHasGlobal(BNDatabase* database,
                                           const char* key) {
  return {};
}
BINARYNINJACOREAPI char* BNReadDatabaseGlobal(BNDatabase* database,
                                              const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteDatabaseGlobal(BNDatabase* database,
                                              const char* key,
                                              const char* val) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNReadDatabaseGlobalData(BNDatabase* database,
                                                          const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteDatabaseGlobalData(BNDatabase* database,
                                                  const char* key,
                                                  BNDataBuffer* val) {
  return {};
}
BINARYNINJACOREAPI BNKeyValueStore* BNReadDatabaseAnalysisCache(
    BNDatabase* database) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteDatabaseAnalysisCache(BNDatabase* database,
                                                     BNKeyValueStore* val) {
  return {};
}
BINARYNINJACOREAPI bool BNSnapshotHasData(BNDatabase* db, int64_t id) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot* BNNewSnapshotReference(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSnapshot(BNSnapshot* snapshot) {}
BINARYNINJACOREAPI void BNFreeSnapshotList(BNSnapshot** snapshots,
                                           size_t count) {}
BINARYNINJACOREAPI BNDatabase* BNGetSnapshotDatabase(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI int64_t BNGetSnapshotId(BNSnapshot* snapshot) { return {}; }
BINARYNINJACOREAPI BNSnapshot* BNGetSnapshotFirstParent(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot** BNGetSnapshotParents(BNSnapshot* snapshot,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot** BNGetSnapshotChildren(BNSnapshot* snapshot,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSnapshotName(BNSnapshot* snapshot) { return {}; }
BINARYNINJACOREAPI void BNSetSnapshotName(BNSnapshot* snapshot,
                                          const char* name) {}
BINARYNINJACOREAPI bool BNIsSnapshotAutoSave(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNSnapshotHasContents(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNSnapshotHasUndo(BNSnapshot* snapshot) { return {}; }
BINARYNINJACOREAPI BNDataBuffer* BNGetSnapshotFileContents(
    BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetSnapshotFileContentsHash(
    BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNKeyValueStore* BNReadSnapshotData(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNKeyValueStore* BNReadSnapshotDataWithProgress(
    BNSnapshot* snapshot, void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetSnapshotUndoData(BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNUndoEntry** BNGetSnapshotUndoEntries(BNSnapshot* snapshot,
                                                          BNFileMetadata* file,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNUndoEntry** BNGetSnapshotUndoEntriesWithProgress(
    BNSnapshot* snapshot, BNFileMetadata* file, void* ctxt,
    BNProgressFunction progress, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNSnapshotHasAncestor(BNSnapshot* snapshot,
                                              BNSnapshot* other) {
  return {};
}
BINARYNINJACOREAPI bool BNSnapshotStoreData(BNSnapshot* snapshot,
                                            BNKeyValueStore* data, void* ctxt,
                                            BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI BNUndoAction* BNNewUndoActionReference(
    BNUndoAction* action) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUndoAction(BNUndoAction* action) {}
BINARYNINJACOREAPI void BNFreeUndoActionList(BNUndoAction** actions,
                                             size_t count) {}
BINARYNINJACOREAPI char* BNUndoActionGetSummaryText(BNUndoAction* action) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNUndoActionGetSummary(
    BNUndoAction* action, size_t* tokenCount) {
  return {};
}
BINARYNINJACOREAPI BNUndoEntry* BNNewUndoEntryReference(BNUndoEntry* entry) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUndoEntry(BNUndoEntry* entry) {}
BINARYNINJACOREAPI void BNFreeUndoEntryList(BNUndoEntry** entrys,
                                            size_t count) {}
BINARYNINJACOREAPI char* BNUndoEntryGetId(BNUndoEntry* entry) { return {}; }
BINARYNINJACOREAPI BNUndoAction** BNUndoEntryGetActions(BNUndoEntry* entry,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNUndoEntryGetTimestamp(BNUndoEntry* entry) {
  return {};
}
BINARYNINJACOREAPI bool BNRebase(BNBinaryView* data, uint64_t address) {
  return {};
}
BINARYNINJACOREAPI bool BNRebaseWithProgress(BNBinaryView* data,
                                             uint64_t address, void* ctxt,
                                             BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI bool BNCreateSnapshotedView(BNBinaryView* data,
                                               const char* viewName) {
  return {};
}
BINARYNINJACOREAPI bool BNCreateSnapshotedViewWithProgress(
    BNBinaryView* data, const char* viewName, void* ctxt,
    BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI char* BNGetOriginalFilename(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI void BNSetOriginalFilename(BNFileMetadata* file,
                                              const char* name) {}
BINARYNINJACOREAPI char* BNGetFilename(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI void BNSetFilename(BNFileMetadata* file, const char* name) {}
BINARYNINJACOREAPI char* BNGetVirtualPath(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI void BNSetVirtualPath(BNFileMetadata* file,
                                         const char* path) {}
BINARYNINJACOREAPI char* BNGetDisplayName(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI void BNSetDisplayName(BNFileMetadata* file,
                                         const char* name) {}
BINARYNINJACOREAPI BNProjectFile* BNGetProjectFile(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI void BNSetProjectFile(BNFileMetadata* file,
                                         BNProjectFile* pfile) {}
BINARYNINJACOREAPI char* BNBeginUndoActions(BNFileMetadata* file,
                                            bool anonymousAllowed) {
  return {};
}
BINARYNINJACOREAPI void BNCommitUndoActions(BNFileMetadata* file,
                                            const char* id) {}
BINARYNINJACOREAPI void BNRevertUndoActions(BNFileMetadata* file,
                                            const char* id) {}
BINARYNINJACOREAPI void BNForgetUndoActions(BNFileMetadata* file,
                                            const char* id) {}
BINARYNINJACOREAPI bool BNCanUndo(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI bool BNUndo(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI bool BNCanRedo(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI bool BNRedo(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI BNUndoEntry** BNGetUndoEntries(BNFileMetadata* file,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNUndoEntry** BNGetRedoEntries(BNFileMetadata* file,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNUndoEntry* BNGetLastUndoEntry(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI BNUndoEntry* BNGetLastRedoEntry(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI char* BNGetLastUndoEntryTitle(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI char* BNGetLastRedoEntryTitle(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUndoEntries(BNUndoEntry** entries, size_t count) {
}
BINARYNINJACOREAPI void BNClearUndoEntries(BNFileMetadata* file) {}
BINARYNINJACOREAPI BNUser* BNNewUserReference(BNUser* user) { return {}; }
BINARYNINJACOREAPI void BNFreeUser(BNUser* user) {}
BINARYNINJACOREAPI BNUser** BNGetUsers(BNFileMetadata* file, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUserList(BNUser** users, size_t count) {}
BINARYNINJACOREAPI char* BNGetUserName(BNUser* user) { return {}; }
BINARYNINJACOREAPI char* BNGetUserEmail(BNUser* user) { return {}; }
BINARYNINJACOREAPI char* BNGetUserId(BNUser* user) { return {}; }
BINARYNINJACOREAPI char* BNGetCurrentView(BNFileMetadata* file) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetCurrentOffset(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI bool BNNavigate(BNFileMetadata* file, const char* view,
                                   uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNGetFileViewOfType(BNFileMetadata* file,
                                                     const char* name) {
  return {};
}
BINARYNINJACOREAPI char** BNGetExistingViews(BNFileMetadata* file,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t BNFileMetadataGetSessionId(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI bool BNIsSnapshotDataAppliedWithoutError(
    BNFileMetadata* view) {
  return {};
}
BINARYNINJACOREAPI void BNUnregisterViewOfType(BNFileMetadata* file,
                                               const char* type,
                                               BNBinaryView* view) {}
BINARYNINJACOREAPI char* BNGetBaseMemoryMapDescription(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI char* BNGetMemoryMapDescription(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetLogicalMemoryMapEnabled(BNBinaryView* view,
                                                     bool enabled) {}
BINARYNINJACOREAPI bool BNIsMemoryMapActivated(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI bool BNAddBinaryMemoryRegion(BNBinaryView* view,
                                                const char* name,
                                                uint64_t start,
                                                BNBinaryView* data,
                                                uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI bool BNAddDataMemoryRegion(BNBinaryView* view,
                                              const char* name, uint64_t start,
                                              BNDataBuffer* data,
                                              uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI bool BNAddUnbackedMemoryRegion(
    BNBinaryView* view, const char* name, uint64_t start, uint64_t length,
    uint32_t flags, uint8_t fill) {
  return {};
}
BINARYNINJACOREAPI bool BNAddRemoteMemoryRegion(BNBinaryView* view,
                                                const char* name,
                                                uint64_t start,
                                                BNFileAccessor* accessor,
                                                uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveMemoryRegion(BNBinaryView* view,
                                             const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetActiveMemoryRegionAt(BNBinaryView* view,
                                                   uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint32_t BNGetMemoryRegionFlags(BNBinaryView* view,
                                                   const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNSetMemoryRegionFlags(BNBinaryView* view,
                                               const char* name,
                                               uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMemoryRegionEnabled(BNBinaryView* view,
                                                const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNSetMemoryRegionEnabled(BNBinaryView* view,
                                                 const char* name,
                                                 bool enable) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMemoryRegionRebaseable(BNBinaryView* view,
                                                   const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNSetMemoryRegionRebaseable(BNBinaryView* view,
                                                    const char* name,
                                                    bool rebaseable) {
  return {};
}
BINARYNINJACOREAPI uint8_t BNGetMemoryRegionFill(BNBinaryView* view,
                                                 const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNSetMemoryRegionFill(BNBinaryView* view,
                                              const char* name, uint8_t fill) {
  return {};
}
BINARYNINJACOREAPI char* BNGetMemoryRegionDisplayName(BNBinaryView* view,
                                                      const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNSetMemoryRegionDisplayName(BNBinaryView* view,
                                                     const char* name,
                                                     const char* displayName) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMemoryRegionLocal(BNBinaryView* view,
                                              const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNGetMemoryRegionInfo(BNBinaryView* view,
                                              const char* name,
                                              BNMemoryRegionInfo* result) {
  return {};
}
BINARYNINJACOREAPI bool BNGetActiveMemoryRegionInfoAt(
    BNBinaryView* view, uint64_t addr, BNMemoryRegionInfo* result) {
  return {};
}
BINARYNINJACOREAPI bool BNGetResolvedMemoryRangeAt(
    BNBinaryView* view, uint64_t addr, BNResolvedMemoryRange* result) {
  return {};
}
BINARYNINJACOREAPI void BNFreeMemoryRegionInfo(BNMemoryRegionInfo* info) {}
BINARYNINJACOREAPI void BNFreeResolvedMemoryRange(
    BNResolvedMemoryRange* range) {}
BINARYNINJACOREAPI BNMemoryRegionInfo* BNGetMemoryRegions(BNBinaryView* view,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeMemoryRegions(BNMemoryRegionInfo* regions,
                                            size_t count) {}
BINARYNINJACOREAPI BNResolvedMemoryRange* BNGetResolvedMemoryRanges(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeResolvedMemoryRanges(
    BNResolvedMemoryRange* ranges, size_t count) {}
BINARYNINJACOREAPI void BNResetMemoryMap(BNBinaryView* view) {}
BINARYNINJACOREAPI BNBinaryView* BNNewViewReference(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBinaryView(BNBinaryView* view) {}
BINARYNINJACOREAPI BNFileMetadata* BNGetFileForView(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI char* BNGetViewType(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI BNBinaryView* BNGetParentView(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI size_t BNReadViewData(BNBinaryView* view, void* dest,
                                         uint64_t offset, size_t len) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNReadViewBuffer(BNBinaryView* view,
                                                  uint64_t offset, size_t len) {
  return {};
}
BINARYNINJACOREAPI const uint8_t* BNGetViewDataPointer(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetViewDataLength(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI size_t BNWriteViewData(BNBinaryView* view, uint64_t offset,
                                          const void* data, size_t len) {
  return {};
}
BINARYNINJACOREAPI size_t BNWriteViewBuffer(BNBinaryView* view, uint64_t offset,
                                            BNDataBuffer* data) {
  return {};
}
BINARYNINJACOREAPI size_t BNInsertViewData(BNBinaryView* view, uint64_t offset,
                                           const void* data, size_t len) {
  return {};
}
BINARYNINJACOREAPI size_t BNInsertViewBuffer(BNBinaryView* view,
                                             uint64_t offset,
                                             BNDataBuffer* data) {
  return {};
}
BINARYNINJACOREAPI size_t BNRemoveViewData(BNBinaryView* view, uint64_t offset,
                                           uint64_t len) {
  return {};
}
BINARYNINJACOREAPI void BNNotifyDataWritten(BNBinaryView* view, uint64_t offset,
                                            size_t len) {}
BINARYNINJACOREAPI void BNNotifyDataInserted(BNBinaryView* view,
                                             uint64_t offset, size_t len) {}
BINARYNINJACOREAPI void BNNotifyDataRemoved(BNBinaryView* view, uint64_t offset,
                                            uint64_t len) {}
BINARYNINJACOREAPI size_t BNGetEntropy(BNBinaryView* view, uint64_t offset,
                                       size_t len, size_t blockSize,
                                       float* result) {
  return {};
}
BINARYNINJACOREAPI BNModificationStatus BNGetModification(BNBinaryView* view,
                                                          uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetModificationArray(BNBinaryView* view,
                                                 uint64_t offset,
                                                 BNModificationStatus* result,
                                                 size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNIsValidOffset(BNBinaryView* view, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetReadable(BNBinaryView* view,
                                           uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetWritable(BNBinaryView* view,
                                           uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetExecutable(BNBinaryView* view,
                                             uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetBackedByFile(BNBinaryView* view,
                                               uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetCodeSemantics(BNBinaryView* view,
                                                uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetExternSemantics(BNBinaryView* view,
                                                  uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetWritableSemantics(BNBinaryView* view,
                                                    uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNIsOffsetReadOnlySemantics(BNBinaryView* view,
                                                    uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetNextValidOffset(BNBinaryView* view,
                                                 uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetImageBase(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetOriginalImageBase(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetOriginalImageBase(BNBinaryView* view,
                                               uint64_t imageBase) {}
BINARYNINJACOREAPI uint64_t BNGetStartOffset(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetEndOffset(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetViewLength(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetEntryPoint(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI BNArchitecture* BNGetDefaultArchitecture(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetDefaultArchitecture(BNBinaryView* view,
                                                 BNArchitecture* arch) {}
BINARYNINJACOREAPI BNPlatform* BNGetDefaultPlatform(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetDefaultPlatform(BNBinaryView* view,
                                             BNPlatform* platform) {}
BINARYNINJACOREAPI BNEndianness BNGetDefaultEndianness(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI bool BNIsRelocatable(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI size_t BNGetViewAddressSize(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI bool BNIsViewModified(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI bool BNIsExecutableView(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI bool BNSaveToFile(BNBinaryView* view, BNFileAccessor* file) {
  return {};
}
BINARYNINJACOREAPI bool BNSaveToFilename(BNBinaryView* view,
                                         const char* filename) {
  return {};
}
BINARYNINJACOREAPI void BNDefineRelocation(BNBinaryView* view,
                                           BNArchitecture* arch,
                                           BNRelocationInfo* info,
                                           uint64_t target, uint64_t reloc) {}
BINARYNINJACOREAPI void BNDefineSymbolRelocation(BNBinaryView* view,
                                                 BNArchitecture* arch,
                                                 BNRelocationInfo* info,
                                                 BNSymbol* target,
                                                 uint64_t reloc) {}
BINARYNINJACOREAPI BNRange* BNGetRelocationRanges(BNBinaryView* view,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRange* BNGetRelocationRangesAtAddress(BNBinaryView* view,
                                                           uint64_t addr,
                                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRange* BNGetRelocationRangesInRange(BNBinaryView* view,
                                                         uint64_t addr,
                                                         uint64_t size,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNRangeContainsRelocation(BNBinaryView* view,
                                                  uint64_t addr, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNRelocation** BNGetRelocationsAt(BNBinaryView* view,
                                                     uint64_t addr,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRelocationList(BNRelocation** relocations,
                                             size_t count) {}
BINARYNINJACOREAPI void BNFreeRelocationRanges(BNRange* ranges) {}
BINARYNINJACOREAPI BNRelocation* BNGetNextRelocation(BNBinaryView* view,
                                                     uint64_t addr,
                                                     uint64_t maxAddr) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterDataNotification(
    BNBinaryView* view, BNBinaryDataNotification* notify) {}
BINARYNINJACOREAPI void BNUnregisterDataNotification(
    BNBinaryView* view, BNBinaryDataNotification* notify) {}
BINARYNINJACOREAPI void BNRegisterProjectNotification(
    BNProject* project, BNProjectNotification* notify) {}
BINARYNINJACOREAPI void BNUnregisterProjectNotification(
    BNProject* project, BNProjectNotification* notify) {}
BINARYNINJACOREAPI bool BNCanAssemble(BNBinaryView* view,
                                      BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI bool BNIsNeverBranchPatchAvailable(BNBinaryView* view,
                                                      BNArchitecture* arch,
                                                      uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNIsAlwaysBranchPatchAvailable(BNBinaryView* view,
                                                       BNArchitecture* arch,
                                                       uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNIsInvertBranchPatchAvailable(BNBinaryView* view,
                                                       BNArchitecture* arch,
                                                       uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNIsSkipAndReturnZeroPatchAvailable(
    BNBinaryView* view, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNIsSkipAndReturnValuePatchAvailable(
    BNBinaryView* view, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNConvertToNop(BNBinaryView* view, BNArchitecture* arch,
                                       uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNAlwaysBranch(BNBinaryView* view, BNArchitecture* arch,
                                       uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNInvertBranch(BNBinaryView* view, BNArchitecture* arch,
                                       uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNSkipAndReturnValue(BNBinaryView* view,
                                             BNArchitecture* arch,
                                             uint64_t addr, uint64_t value) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetInstructionLength(BNBinaryView* view,
                                                 BNArchitecture* arch,
                                                 uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNFindNextData(BNBinaryView* view, uint64_t start,
                                       BNDataBuffer* data, uint64_t* result,
                                       BNFindFlag flags) {
  return {};
}
BINARYNINJACOREAPI bool BNFindNextText(BNBinaryView* view, uint64_t start,
                                       const char* data, uint64_t* result,
                                       BNDisassemblySettings* settings,
                                       BNFindFlag flags,
                                       BNFunctionViewType viewType) {
  return {};
}
BINARYNINJACOREAPI bool BNFindNextConstant(BNBinaryView* view, uint64_t start,
                                           uint64_t constant, uint64_t* result,
                                           BNDisassemblySettings* settings,
                                           BNFunctionViewType viewType) {
  return {};
}
BINARYNINJACOREAPI bool BNFindNextDataWithProgress(
    BNBinaryView* view, uint64_t start, uint64_t end, BNDataBuffer* data,
    uint64_t* result, BNFindFlag flags, void* ctxt,
    BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI bool BNFindNextTextWithProgress(
    BNBinaryView* view, uint64_t start, uint64_t end, const char* data,
    uint64_t* result, BNDisassemblySettings* settings, BNFindFlag flags,
    BNFunctionViewType viewType, void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI bool BNFindNextConstantWithProgress(
    BNBinaryView* view, uint64_t start, uint64_t end, uint64_t constant,
    uint64_t* result, BNDisassemblySettings* settings,
    BNFunctionViewType viewType, void* ctxt, BNProgressFunction progress) {
  return {};
}
BINARYNINJACOREAPI bool BNFindAllDataWithProgress(
    BNBinaryView* view, uint64_t start, uint64_t end, BNDataBuffer* data,
    BNFindFlag flags, void* ctxt, BNProgressFunction progress, void* matchCtxt,
    bool (*matchCallback)(void* matchCtxt, uint64_t addr,
                          BNDataBuffer* match)) {
  return {};
}
BINARYNINJACOREAPI bool BNFindAllTextWithProgress(
    BNBinaryView* view, uint64_t start, uint64_t end, const char* data,
    BNDisassemblySettings* settings, BNFindFlag flags,
    BNFunctionViewType viewType, void* ctxt, BNProgressFunction progress,
    void* matchCtxt,
    bool (*matchCallback)(void* matchCtxt, uint64_t addr, const char* match,
                          BNLinearDisassemblyLine* line)) {
  return {};
}
BINARYNINJACOREAPI bool BNFindAllConstantWithProgress(
    BNBinaryView* view, uint64_t start, uint64_t end, uint64_t constant,
    BNDisassemblySettings* settings, BNFunctionViewType viewType, void* ctxt,
    BNProgressFunction progress, void* matchCtxt,
    bool (*matchCallback)(void* matchCtxt, uint64_t addr,
                          BNLinearDisassemblyLine* line)) {
  return {};
}
BINARYNINJACOREAPI bool BNSearch(
    BNBinaryView* view, const char* query, void* context,
    BNProgressFunction progressCallback, void* matchContext,
    bool (*callback)(void*, uint64_t, BNDataBuffer*)) {
  return {};
}
BINARYNINJACOREAPI char* BNDetectSearchMode(const char* query) { return {}; }
BINARYNINJACOREAPI bool BNPerformSearch(const char* query,
                                        const uint8_t* buffer, size_t size,
                                        BNProgressFunction callback,
                                        void* context) {
  return {};
}
BINARYNINJACOREAPI void BNBeginBulkAddSegments(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNEndBulkAddSegments(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNCancelBulkAddSegments(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNAddAutoSegment(BNBinaryView* view, uint64_t start,
                                         uint64_t length, uint64_t dataOffset,
                                         uint64_t dataLength, uint32_t flags) {}
BINARYNINJACOREAPI void BNAddAutoSegments(BNBinaryView* view,
                                          const BNSegmentInfo* segmentInfo,
                                          size_t count) {}
BINARYNINJACOREAPI void BNRemoveAutoSegment(BNBinaryView* view, uint64_t start,
                                            uint64_t length) {}
BINARYNINJACOREAPI void BNAddUserSegment(BNBinaryView* view, uint64_t start,
                                         uint64_t length, uint64_t dataOffset,
                                         uint64_t dataLength, uint32_t flags) {}
BINARYNINJACOREAPI void BNAddUserSegments(BNBinaryView* view,
                                          const BNSegmentInfo* segmentInfo,
                                          size_t count) {}
BINARYNINJACOREAPI void BNRemoveUserSegment(BNBinaryView* view, uint64_t start,
                                            uint64_t length) {}
BINARYNINJACOREAPI BNSegment** BNGetSegments(BNBinaryView* view,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSegmentList(BNSegment** segments, size_t count) {}
BINARYNINJACOREAPI BNSegment* BNGetSegmentAt(BNBinaryView* view,
                                             uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNGetAddressForDataOffset(BNBinaryView* view,
                                                  uint64_t offset,
                                                  uint64_t* addr) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNGetComponentByGuid(BNBinaryView* view,
                                                     const char* guid) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNGetRootComponent(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNCreateComponent(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNCreateComponentWithParent(
    BNBinaryView* view, const char* parentGUID) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNCreateComponentWithName(BNBinaryView* view,
                                                          const char* name) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNCreateComponentWithParentAndName(
    BNBinaryView* view, const char* parentGUID, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNGetComponentByPath(BNBinaryView* view,
                                                     const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveComponent(BNBinaryView* view,
                                          BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveComponentByGuid(BNBinaryView* view,
                                                const char* guid) {
  return {};
}
BINARYNINJACOREAPI void BNAddAutoSection(
    BNBinaryView* view, const char* name, uint64_t start, uint64_t length,
    BNSectionSemantics semantics, const char* type, uint64_t align,
    uint64_t entrySize, const char* linkedSection, const char* infoSection,
    uint64_t infoData) {}
BINARYNINJACOREAPI void BNAddAutoSections(BNBinaryView* view,
                                          const BNSectionInfo* sectionInfo,
                                          size_t count) {}
BINARYNINJACOREAPI void BNRemoveAutoSection(BNBinaryView* view,
                                            const char* name) {}
BINARYNINJACOREAPI void BNAddUserSection(
    BNBinaryView* view, const char* name, uint64_t start, uint64_t length,
    BNSectionSemantics semantics, const char* type, uint64_t align,
    uint64_t entrySize, const char* linkedSection, const char* infoSection,
    uint64_t infoData) {}
BINARYNINJACOREAPI void BNAddUserSections(BNBinaryView* view,
                                          const BNSectionInfo* sectionInfo,
                                          size_t count) {}
BINARYNINJACOREAPI void BNRemoveUserSection(BNBinaryView* view,
                                            const char* name) {}
BINARYNINJACOREAPI BNSection** BNGetSections(BNBinaryView* view,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSection** BNGetSectionsAt(BNBinaryView* view,
                                               uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSectionList(BNSection** sections, size_t count) {}
BINARYNINJACOREAPI BNSection* BNGetSectionByName(BNBinaryView* view,
                                                 const char* name) {
  return {};
}
BINARYNINJACOREAPI char** BNGetUniqueSectionNames(BNBinaryView* view,
                                                  const char** names,
                                                  size_t count) {
  return {};
}
BINARYNINJACOREAPI BNAddressRange* BNGetAllocatedRanges(BNBinaryView* view,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNAddressRange* BNGetMappedAddressRanges(BNBinaryView* view,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNAddressRange* BNGetBackedAddressRanges(BNBinaryView* view,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAddressRanges(BNAddressRange* ranges) {}
BINARYNINJACOREAPI BNNameSpace* BNGetNameSpaces(BNBinaryView* view,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeNameSpaceList(BNNameSpace* nameSpace,
                                            size_t count) {}
BINARYNINJACOREAPI BNNameSpace BNGetExternalNameSpace(void) { return {}; }
BINARYNINJACOREAPI BNNameSpace BNGetInternalNameSpace(void) { return {}; }
BINARYNINJACOREAPI void BNFreeNameSpace(BNNameSpace* name) {}
BINARYNINJACOREAPI BNRegisterValueWithConfidenceAndRegister*
BNGetGlobalPointerValues(BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValueWithConfidenceAndRegister*
BNGetDefaultGlobalPointerValues(BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValueWithConfidenceAndRegister*
BNGetUserGlobalPointerValues(BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRegisterValueWithConfidenceAndRegisterList(
    BNRegisterValueWithConfidenceAndRegister* values) {}
BINARYNINJACOREAPI bool BNUserGlobalPointerValuesSet(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNClearUserGlobalPointerValues(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNSetUserGlobalPointerValues(
    BNBinaryView* view, const BNRegisterValueWithConfidenceAndRegister* values,
    size_t count) {}
BINARYNINJACOREAPI bool BNStringifyUnicodeData(
    BNBinaryView* data, BNArchitecture* arch, const BNDataBuffer* buffer,
    bool nullTerminates, bool allowShortStrings, char** string,
    BNStringType* type) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateBinaryDataView(BNFileMetadata* file) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateBinaryDataViewFromBuffer(
    BNFileMetadata* file, BNDataBuffer* buf) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateBinaryDataViewFromData(
    BNFileMetadata* file, const void* data, size_t len) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateBinaryDataViewFromFilename(
    BNFileMetadata* file, const char* filename) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateBinaryDataViewFromFile(
    BNFileMetadata* file, BNFileAccessor* accessor) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateCustomBinaryView(
    const char* name, BNFileMetadata* file, BNBinaryView* parent,
    BNCustomBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNBinaryViewType* BNGetBinaryViewTypeByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNBinaryViewType** BNGetBinaryViewTypes(size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBinaryViewType** BNGetBinaryViewTypesForData(
    BNBinaryView* data, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBinaryViewTypeList(BNBinaryViewType** types) {}
BINARYNINJACOREAPI char* BNGetBinaryViewTypeName(BNBinaryViewType* type) {
  return {};
}
BINARYNINJACOREAPI char* BNGetBinaryViewTypeLongName(BNBinaryViewType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNIsBinaryViewTypeDeprecated(BNBinaryViewType* type) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNCreateBinaryViewOfType(
    BNBinaryViewType* type, BNBinaryView* data) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNParseBinaryViewOfType(BNBinaryViewType* type,
                                                         BNBinaryView* data) {
  return {};
}
BINARYNINJACOREAPI bool BNIsBinaryViewTypeValidForData(BNBinaryViewType* type,
                                                       BNBinaryView* data) {
  return {};
}
BINARYNINJACOREAPI bool BNIsBinaryViewTypeForceLoadable(
    BNBinaryViewType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewTypeHasNoInitialContent(
    BNBinaryViewType* type) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNGetBinaryViewDefaultLoadSettingsForData(
    BNBinaryViewType* type, BNBinaryView* data) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNGetBinaryViewLoadSettingsForData(
    BNBinaryViewType* type, BNBinaryView* data) {
  return {};
}
BINARYNINJACOREAPI BNBinaryViewType* BNRegisterBinaryViewType(
    const char* name, const char* longName, BNCustomBinaryViewType* type) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterArchitectureForViewType(
    BNBinaryViewType* type, uint32_t id, BNEndianness endian,
    BNArchitecture* arch) {}
BINARYNINJACOREAPI BNArchitecture* BNGetArchitectureForViewType(
    BNBinaryViewType* type, uint32_t id, BNEndianness endian) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterPlatformForViewType(BNBinaryViewType* type,
                                                      uint32_t id,
                                                      BNArchitecture* arch,
                                                      BNPlatform* platform) {}
BINARYNINJACOREAPI BNPlatform* BNGetPlatformForViewType(BNBinaryViewType* type,
                                                        uint32_t id,
                                                        BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterDefaultPlatformForViewType(
    BNBinaryViewType* type, BNArchitecture* arch, BNPlatform* platform) {}
BINARYNINJACOREAPI void BNRegisterPlatformRecognizerForViewType(
    BNBinaryViewType* type, uint64_t id, BNEndianness endian,
    BNPlatform* (*callback)(void* ctx, BNBinaryView* view,
                            BNMetadata* metadata),
    void* ctx) {}
BINARYNINJACOREAPI BNPlatform* BNRecognizePlatformForViewType(
    BNBinaryViewType* type, uint64_t id, BNEndianness endian,
    BNBinaryView* view, BNMetadata* metadata) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterBinaryViewEvent(
    BNBinaryViewEventType type, void (*callback)(void* ctx, BNBinaryView* view),
    void* ctx) {}
BINARYNINJACOREAPI BNBinaryReader* BNCreateBinaryReader(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBinaryReader(BNBinaryReader* stream) {}
BINARYNINJACOREAPI BNEndianness
BNGetBinaryReaderEndianness(BNBinaryReader* stream) {
  return {};
}
BINARYNINJACOREAPI void BNSetBinaryReaderEndianness(BNBinaryReader* stream,
                                                    BNEndianness endian) {}
BINARYNINJACOREAPI bool BNReadData(BNBinaryReader* stream, void* dest,
                                   size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNRead8(BNBinaryReader* stream, uint8_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNRead16(BNBinaryReader* stream, uint16_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNRead32(BNBinaryReader* stream, uint32_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNRead64(BNBinaryReader* stream, uint64_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadLE16(BNBinaryReader* stream, uint16_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadLE32(BNBinaryReader* stream, uint32_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadLE64(BNBinaryReader* stream, uint64_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadBE16(BNBinaryReader* stream, uint16_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadBE32(BNBinaryReader* stream, uint32_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadBE64(BNBinaryReader* stream, uint64_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNReadPointer(BNBinaryView* view,
                                      BNBinaryReader* stream,
                                      uint64_t* result) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetReaderPosition(BNBinaryReader* stream) {
  return {};
}
BINARYNINJACOREAPI void BNSeekBinaryReader(BNBinaryReader* stream,
                                           uint64_t offset) {}
BINARYNINJACOREAPI void BNSeekBinaryReaderRelative(BNBinaryReader* stream,
                                                   int64_t offset) {}
BINARYNINJACOREAPI uint64_t
BNGetBinaryReaderVirtualBase(BNBinaryReader* stream) {
  return {};
}
BINARYNINJACOREAPI void BNSetBinaryReaderVirtualBase(BNBinaryReader* stream,
                                                     uint64_t base) {}
BINARYNINJACOREAPI bool BNIsEndOfFile(BNBinaryReader* stream) { return {}; }
BINARYNINJACOREAPI BNBinaryWriter* BNCreateBinaryWriter(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBinaryWriter(BNBinaryWriter* stream) {}
BINARYNINJACOREAPI BNEndianness
BNGetBinaryWriterEndianness(BNBinaryWriter* stream) {
  return {};
}
BINARYNINJACOREAPI void BNSetBinaryWriterEndianness(BNBinaryWriter* stream,
                                                    BNEndianness endian) {}
BINARYNINJACOREAPI bool BNWriteData(BNBinaryWriter* stream, const void* src,
                                    size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNWrite8(BNBinaryWriter* stream, uint8_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWrite16(BNBinaryWriter* stream, uint16_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWrite32(BNBinaryWriter* stream, uint32_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWrite64(BNBinaryWriter* stream, uint64_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteLE16(BNBinaryWriter* stream, uint16_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteLE32(BNBinaryWriter* stream, uint32_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteLE64(BNBinaryWriter* stream, uint64_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteBE16(BNBinaryWriter* stream, uint16_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteBE32(BNBinaryWriter* stream, uint32_t val) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteBE64(BNBinaryWriter* stream, uint64_t val) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetWriterPosition(BNBinaryWriter* stream) {
  return {};
}
BINARYNINJACOREAPI void BNSeekBinaryWriter(BNBinaryWriter* stream,
                                           uint64_t offset) {}
BINARYNINJACOREAPI void BNSeekBinaryWriterRelative(BNBinaryWriter* stream,
                                                   int64_t offset) {}
BINARYNINJACOREAPI BNTransform* BNGetTransformByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNTransform** BNGetTransformTypeList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTransformTypeList(BNTransform** xforms) {}
BINARYNINJACOREAPI BNTransform* BNRegisterTransformType(
    BNTransformType type, const char* name, const char* longName,
    const char* group, BNCustomTransform* xform) {
  return {};
}
BINARYNINJACOREAPI BNTransform* BNRegisterTransformTypeWithCapabilities(
    BNTransformType type, uint32_t capabilities, const char* name,
    const char* longName, const char* group, BNCustomTransform* xform) {
  return {};
}
BINARYNINJACOREAPI BNTransformType BNGetTransformType(BNTransform* xform) {
  return {};
}
BINARYNINJACOREAPI uint32_t BNGetTransformCapabilities(BNTransform* xform) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformSupportsDetection(BNTransform* xform) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformSupportsContext(BNTransform* xform) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTransformName(BNTransform* xform) { return {}; }
BINARYNINJACOREAPI char* BNGetTransformLongName(BNTransform* xform) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTransformGroup(BNTransform* xform) { return {}; }
BINARYNINJACOREAPI BNTransformParameterInfo* BNGetTransformParameterList(
    BNTransform* xform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTransformParameterList(
    BNTransformParameterInfo* params, size_t count) {}
BINARYNINJACOREAPI bool BNDecode(BNTransform* xform, BNDataBuffer* input,
                                 BNDataBuffer* output,
                                 BNTransformParameter* params,
                                 size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI bool BNEncode(BNTransform* xform, BNDataBuffer* input,
                                 BNDataBuffer* output,
                                 BNTransformParameter* params,
                                 size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI bool BNDecodeWithContext(BNTransform* xform,
                                            BNTransformContext* context,
                                            BNTransformParameter* params,
                                            size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI bool BNCanDecode(BNTransform* xform, BNBinaryView* input) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext* BNNewTransformContextReference(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTransformContext(BNTransformContext* context) {}
BINARYNINJACOREAPI BNBinaryView* BNTransformContextGetInput(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI char* BNTransformContextGetFileName(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI char** BNTransformContextGetAvailableTransforms(
    BNTransformContext* context, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNTransformContextGetTransformName(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI void BNTransformContextSetTransformName(
    BNTransformContext* context, const char* transformName) {}
BINARYNINJACOREAPI void BNTransformContextSetTransformParameters(
    BNTransformContext* context, BNTransformParameter* params,
    size_t paramCount) {}
BINARYNINJACOREAPI void BNTransformContextSetTransformParameter(
    BNTransformContext* context, const char* name, BNDataBuffer* data) {}
BINARYNINJACOREAPI bool BNTransformContextHasTransformParameter(
    BNTransformContext* context, const char* name) {
  return {};
}
BINARYNINJACOREAPI void BNTransformContextClearTransformParameter(
    BNTransformContext* context, const char* name) {}
BINARYNINJACOREAPI char* BNTransformContextGetExtractionMessage(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI BNTransformResult
BNTransformContextGetExtractionResult(BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI BNTransformResult
BNTransformContextGetTransformResult(BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI void BNTransformContextSetTransformResult(
    BNTransformContext* context, BNTransformResult result) {}
BINARYNINJACOREAPI BNMetadata* BNTransformContextGetMetadata(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext* BNTransformContextGetParent(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI size_t
BNTransformContextGetChildCount(BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext** BNTransformContextGetChildren(
    BNTransformContext* context, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTransformContextList(
    BNTransformContext** contexts, size_t count) {}
BINARYNINJACOREAPI BNTransformContext* BNTransformContextGetChild(
    BNTransformContext* context, const char* filename) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext* BNTransformContextSetChild(
    BNTransformContext* context, BNDataBuffer* data, const char* filename,
    BNTransformResult result, const char* message, bool filenameIsDescriptor) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformContextIsLeaf(BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformContextIsRoot(BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI char** BNTransformContextGetAvailableFiles(
    BNTransformContext* context, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNTransformContextSetAvailableFiles(
    BNTransformContext* context, const char** files, size_t count) {}
BINARYNINJACOREAPI bool BNTransformContextHasAvailableFiles(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI char** BNTransformContextGetRequestedFiles(
    BNTransformContext* context, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNTransformContextSetRequestedFiles(
    BNTransformContext* context, const char** files, size_t count) {}
BINARYNINJACOREAPI bool BNTransformContextHasRequestedFiles(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformContextIsDatabase(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformContextIsInteractive(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNTransformContextGetSettings(
    BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI BNTransformSession* BNCreateTransformSession(
    const char* filename, const char* options) {
  return {};
}
BINARYNINJACOREAPI BNTransformSession* BNCreateTransformSessionWithMode(
    const char* filename, BNTransformSessionMode mode, const char* options) {
  return {};
}
BINARYNINJACOREAPI BNTransformSession* BNCreateTransformSessionFromBinaryView(
    BNBinaryView* initialView, const char* options) {
  return {};
}
BINARYNINJACOREAPI BNTransformSession*
BNCreateTransformSessionFromBinaryViewWithMode(BNBinaryView* initialView,
                                               BNTransformSessionMode mode,
                                               const char* options) {
  return {};
}
BINARYNINJACOREAPI BNTransformSession*
BNCreateTransformSessionFromTransformContextWithMode(
    BNTransformContext* context, BNTransformSessionMode mode,
    const char* options) {
  return {};
}
BINARYNINJACOREAPI BNTransformSession* BNNewTransformSessionReference(
    BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTransformSession(BNTransformSession* session) {}
BINARYNINJACOREAPI void BNTransformSessionSetInteractive(
    BNTransformSession* session, bool interactive) {}
BINARYNINJACOREAPI BNBinaryView* BNTransformSessionGetCurrentView(
    BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext* BNTransformSessionGetRootContext(
    BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext* BNTransformSessionGetCurrentContext(
    BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformSessionProcessFrom(
    BNTransformSession* session, BNTransformContext* context) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformSessionProcess(BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformSessionHasAnyStages(
    BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI bool BNTransformSessionHasSinglePath(
    BNTransformSession* session) {
  return {};
}
BINARYNINJACOREAPI BNTransformContext** BNTransformSessionGetSelectedContexts(
    BNTransformSession* session, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNTransformSessionSetSelectedContexts(
    BNTransformSession* session, BNTransformContext** contexts, size_t count) {}
BINARYNINJACOREAPI BNArchitecture* BNGetArchitectureByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture** BNGetArchitectureList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeArchitectureList(BNArchitecture** archs) {}
BINARYNINJACOREAPI BNArchitecture* BNRegisterArchitecture(
    const char* name, BNCustomArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNRegisterArchitectureExtension(
    const char* name, BNArchitecture* base, BNCustomArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNAddArchitectureRedirection(BNArchitecture* arch,
                                                     BNArchitecture* from,
                                                     BNArchitecture* to) {}
BINARYNINJACOREAPI BNArchitecture* BNRegisterArchitectureHook(
    BNArchitecture* base, BNCustomArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNFinalizeArchitectureHook(BNArchitecture* base) {}
BINARYNINJACOREAPI BNArchitecture* BNGetNativeTypeParserArchitecture(void) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureName(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNEndianness
BNGetArchitectureEndianness(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetArchitectureAddressSize(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetArchitectureDefaultIntegerSize(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetArchitectureInstructionAlignment(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetArchitectureLinearSweepInitialAlignment(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetArchitectureLinearSweepAnalysisCapabilities(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetArchitectureMaxInstructionLength(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetArchitectureOpcodeDisplayLength(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNGetAssociatedArchitectureByAddress(
    BNArchitecture* arch, uint64_t* addr) {
  return {};
}
BINARYNINJACOREAPI bool BNGetInstructionInfo(BNArchitecture* arch,
                                             const uint8_t* data, uint64_t addr,
                                             size_t maxLen,
                                             BNInstructionInfo* result) {
  return {};
}
BINARYNINJACOREAPI bool BNGetInstructionText(BNArchitecture* arch,
                                             const uint8_t* data, uint64_t addr,
                                             size_t* len,
                                             BNInstructionTextToken** result,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetInstructionTextWithContext(
    BNArchitecture* arch, const uint8_t* data, uint64_t addr, size_t* len,
    void* context, BNInstructionTextToken** result, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetInstructionLowLevelIL(BNArchitecture* arch,
                                                   const uint8_t* data,
                                                   uint64_t addr, size_t* len,
                                                   BNLowLevelILFunction* il) {
  return {};
}
BINARYNINJACOREAPI void BNFreeInstructionText(BNInstructionTextToken* tokens,
                                              size_t count) {}
BINARYNINJACOREAPI bool BNArchitectureSetDefaultAnalyzeBasicBlocksCallback(
    void* callback) {
  return {};
}
BINARYNINJACOREAPI void BNArchitectureDefaultAnalyzeBasicBlocks(
    BNFunction* function, BNBasicBlockAnalysisContext* context) {}
BINARYNINJACOREAPI void BNArchitectureAnalyzeBasicBlocks(
    BNArchitecture* arch, BNFunction* function,
    BNBasicBlockAnalysisContext* context) {}
BINARYNINJACOREAPI bool BNArchitectureSetDefaultLiftFunctionCallback(
    void* callback) {
  return {};
}
BINARYNINJACOREAPI bool BNArchitectureDefaultLiftFunction(
    BNLowLevelILFunction* function, BNFunctionLifterContext* context) {
  return {};
}
BINARYNINJACOREAPI bool BNArchitectureLiftFunction(
    BNArchitecture* arch, BNLowLevelILFunction* function,
    BNFunctionLifterContext* context) {
  return {};
}
BINARYNINJACOREAPI void BNArchitectureFreeFunctionArchContext(
    BNArchitecture* arch, void* context) {}
BINARYNINJACOREAPI void BNFreeInstructionTextLines(BNInstructionTextLine* lines,
                                                   size_t count) {}
BINARYNINJACOREAPI char* BNGetArchitectureRegisterName(BNArchitecture* arch,
                                                       uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureFlagName(BNArchitecture* arch,
                                                   uint32_t flag) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureFlagWriteTypeName(
    BNArchitecture* arch, uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureSemanticFlagClassName(
    BNArchitecture* arch, uint32_t semClass) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureSemanticFlagGroupName(
    BNArchitecture* arch, uint32_t semGroup) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetFullWidthArchitectureRegisters(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureRegisters(BNArchitecture* arch,
                                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureFlags(BNArchitecture* arch,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureFlagWriteTypes(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureSemanticFlagClasses(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureSemanticFlagGroups(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFlagRole BNGetArchitectureFlagRole(BNArchitecture* arch,
                                                        uint32_t flag,
                                                        uint32_t semClass) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetArchitectureFlagsRequiredForFlagCondition(
    BNArchitecture* arch, BNLowLevelILFlagCondition cond, uint32_t semClass,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetArchitectureFlagsRequiredForSemanticFlagGroup(
    BNArchitecture* arch, uint32_t semGroup, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFlagConditionForSemanticClass*
BNGetArchitectureFlagConditionsForSemanticFlagGroup(BNArchitecture* arch,
                                                    uint32_t semGroup,
                                                    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlagConditionsForSemanticFlagGroup(
    BNFlagConditionForSemanticClass* conditions) {}
BINARYNINJACOREAPI uint32_t* BNGetArchitectureFlagsWrittenByFlagWriteType(
    BNArchitecture* arch, uint32_t writeType, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t BNGetArchitectureSemanticClassForFlagWriteType(
    BNArchitecture* arch, uint32_t writeType) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetArchitectureFlagWriteLowLevelIL(
    BNArchitecture* arch, BNLowLevelILOperation op, size_t size,
    uint32_t flagWriteType, uint32_t flag, BNRegisterOrConstant* operands,
    size_t operandCount, BNLowLevelILFunction* il) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetDefaultArchitectureFlagWriteLowLevelIL(
    BNArchitecture* arch, BNLowLevelILOperation op, size_t size,
    BNFlagRole role, BNRegisterOrConstant* operands, size_t operandCount,
    BNLowLevelILFunction* il) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetArchitectureFlagConditionLowLevelIL(
    BNArchitecture* arch, BNLowLevelILFlagCondition cond, uint32_t semClass,
    BNLowLevelILFunction* il) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetDefaultArchitectureFlagConditionLowLevelIL(
    BNArchitecture* arch, BNLowLevelILFlagCondition cond, uint32_t semClass,
    BNLowLevelILFunction* il) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetArchitectureSemanticFlagGroupLowLevelIL(
    BNArchitecture* arch, uint32_t semGroup, BNLowLevelILFunction* il) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetModifiedArchitectureRegistersOnWrite(
    BNArchitecture* arch, uint32_t reg, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRegisterList(uint32_t* regs) {}
BINARYNINJACOREAPI BNRegisterInfo
BNGetArchitectureRegisterInfo(BNArchitecture* arch, uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetArchitectureStackPointerRegister(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetArchitectureLinkRegister(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetArchitectureGlobalRegisters(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureGlobalRegister(BNArchitecture* arch,
                                                       uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetArchitectureSystemRegisters(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureSystemRegister(BNArchitecture* arch,
                                                       uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetArchitectureRegisterByName(BNArchitecture* arch, const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureRegisterStackName(
    BNArchitecture* arch, uint32_t regStack) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureRegisterStacks(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterStackInfo
BNGetArchitectureRegisterStackInfo(BNArchitecture* arch, uint32_t regStack) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetArchitectureRegisterStackForRegister(BNArchitecture* arch, uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI BNIntrinsicClass
BNGetArchitectureIntrinsicClass(BNArchitecture* arch, uint32_t intrinsic) {
  return {};
}
BINARYNINJACOREAPI char* BNGetArchitectureIntrinsicName(BNArchitecture* arch,
                                                        uint32_t intrinsic) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetAllArchitectureIntrinsics(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNNameAndType* BNGetArchitectureIntrinsicInputs(
    BNArchitecture* arch, uint32_t intrinsic, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeNameAndTypeList(BNNameAndType* nt, size_t count) {
}
BINARYNINJACOREAPI BNTypeWithConfidence* BNGetArchitectureIntrinsicOutputs(
    BNArchitecture* arch, uint32_t intrinsic, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeOutputTypeList(BNTypeWithConfidence* types,
                                             size_t count) {}
BINARYNINJACOREAPI bool BNCanArchitectureAssemble(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI bool BNAssemble(BNArchitecture* arch, const char* code,
                                   uint64_t addr, BNDataBuffer* result,
                                   char** errors) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureNeverBranchPatchAvailable(
    BNArchitecture* arch, const uint8_t* data, uint64_t addr, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureAlwaysBranchPatchAvailable(
    BNArchitecture* arch, const uint8_t* data, uint64_t addr, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureInvertBranchPatchAvailable(
    BNArchitecture* arch, const uint8_t* data, uint64_t addr, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureSkipAndReturnZeroPatchAvailable(
    BNArchitecture* arch, const uint8_t* data, uint64_t addr, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArchitectureSkipAndReturnValuePatchAvailable(
    BNArchitecture* arch, const uint8_t* data, uint64_t addr, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNArchitectureConvertToNop(BNArchitecture* arch,
                                                   uint8_t* data, uint64_t addr,
                                                   size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNArchitectureAlwaysBranch(BNArchitecture* arch,
                                                   uint8_t* data, uint64_t addr,
                                                   size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNArchitectureInvertBranch(BNArchitecture* arch,
                                                   uint8_t* data, uint64_t addr,
                                                   size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNArchitectureSkipAndReturnValue(BNArchitecture* arch,
                                                         uint8_t* data,
                                                         uint64_t addr,
                                                         size_t len,
                                                         uint64_t value) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterArchitectureFunctionRecognizer(
    BNArchitecture* arch, BNFunctionRecognizer* rec) {}
BINARYNINJACOREAPI void BNArchitectureRegisterRelocationHandler(
    BNArchitecture* arch, const char* viewName, BNRelocationHandler* handler) {}
BINARYNINJACOREAPI BNRelocationHandler* BNCreateRelocationHandler(
    BNCustomRelocationHandler* handler) {
  return {};
}
BINARYNINJACOREAPI BNRelocationHandler* BNArchitectureGetRelocationHandler(
    BNArchitecture* arch, const char* viewName) {
  return {};
}
BINARYNINJACOREAPI BNRelocationHandler* BNNewRelocationHandlerReference(
    BNRelocationHandler* handler) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRelocationHandler(BNRelocationHandler* handler) {}
BINARYNINJACOREAPI bool BNRelocationHandlerGetRelocationInfo(
    BNRelocationHandler* handler, BNBinaryView* data, BNArchitecture* arch,
    BNRelocationInfo* info, size_t infoCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRelocationHandlerApplyRelocation(
    BNRelocationHandler* handler, BNBinaryView* view, BNArchitecture* arch,
    BNRelocation* reloc, uint8_t* dest, size_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNRelocationHandlerDefaultApplyRelocation(
    BNRelocationHandler* handler, BNBinaryView* view, BNArchitecture* arch,
    BNRelocation* reloc, uint8_t* dest, size_t len) {
  return {};
}
BINARYNINJACOREAPI size_t BNRelocationHandlerGetOperandForExternalRelocation(
    BNRelocationHandler* handler, const uint8_t* data, uint64_t addr,
    size_t length, const BNLowLevelILFunction* il, BNRelocation* relocation) {
  return {};
}
BINARYNINJACOREAPI void BNAddAnalysisOption(BNBinaryView* view,
                                            const char* name) {}
BINARYNINJACOREAPI BNFunction* BNAddFunctionForAnalysis(BNBinaryView* view,
                                                        BNPlatform* platform,
                                                        uint64_t addr,
                                                        bool autoDiscovered,
                                                        BNType* type) {
  return {};
}
BINARYNINJACOREAPI void BNAddEntryPointForAnalysis(BNBinaryView* view,
                                                   BNPlatform* platform,
                                                   uint64_t addr) {}
BINARYNINJACOREAPI void BNRemoveAnalysisFunction(BNBinaryView* view,
                                                 BNFunction* func,
                                                 bool updateRefs) {}
BINARYNINJACOREAPI BNFunction* BNCreateUserFunction(BNBinaryView* view,
                                                    BNPlatform* platform,
                                                    uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNRemoveUserFunction(BNBinaryView* view,
                                             BNFunction* func) {}
BINARYNINJACOREAPI bool BNHasInitialAnalysis(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI void BNSetAnalysisHold(BNBinaryView* view, bool enable) {}
BINARYNINJACOREAPI bool BNGetFunctionAnalysisUpdateDisabled(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetFunctionAnalysisUpdateDisabled(BNBinaryView* view,
                                                            bool disabled) {}
BINARYNINJACOREAPI void BNUpdateAnalysisAndWait(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNUpdateAnalysis(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNAbortAnalysis(BNBinaryView* view) {}
BINARYNINJACOREAPI bool BNAnalysisIsAborted(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI bool BNIsFunctionUpdateNeeded(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNRequestAdvancedFunctionAnalysisData(
    BNFunction* func) {}
BINARYNINJACOREAPI void BNReleaseAdvancedFunctionAnalysisData(
    BNFunction* func) {}
BINARYNINJACOREAPI void BNReleaseAdvancedFunctionAnalysisDataMultiple(
    BNFunction* func, size_t count) {}
BINARYNINJACOREAPI BNFunction* BNNewFunctionReference(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFunction(BNFunction* func) {}
BINARYNINJACOREAPI BNFunction** BNGetAnalysisFunctionList(BNBinaryView* view,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFunctionList(BNFunction** funcs, size_t count) {}
BINARYNINJACOREAPI bool BNHasFunctions(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI bool BNHasSymbols(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI bool BNHasDataVariables(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI BNFunction* BNGetAnalysisFunction(BNBinaryView* view,
                                                     BNPlatform* platform,
                                                     uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNGetRecentAnalysisFunctionForAddress(
    BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNFunction** BNGetAnalysisFunctionsForAddress(
    BNBinaryView* view, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFunction** BNGetAnalysisFunctionsContainingAddress(
    BNBinaryView* view, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNGetAnalysisEntryPoint(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNFunction** BNGetAllEntryFunctions(BNBinaryView* view,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddToEntryFunctions(BNBinaryView* view,
                                              BNFunction* func) {}
BINARYNINJACOREAPI char* BNGetGlobalCommentForAddress(BNBinaryView* view,
                                                      uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetGlobalCommentedAddresses(BNBinaryView* view,
                                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSetGlobalCommentForAddress(BNBinaryView* view,
                                                     uint64_t addr,
                                                     const char* comment) {}
BINARYNINJACOREAPI BNBinaryView* BNGetFunctionData(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNGetFunctionArchitecture(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNGetFunctionPlatform(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetFunctionStart(BNFunction* func) { return {}; }
BINARYNINJACOREAPI BNSymbol* BNGetFunctionSymbol(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI bool BNWasFunctionAutomaticallyDiscovered(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI bool BNFunctionHasUserAnnotations(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence BNCanFunctionReturn(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence BNIsFunctionPure(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNSetFunctionAutoType(BNFunction* func, BNType* type) {}
BINARYNINJACOREAPI void BNSetFunctionUserType(BNFunction* func, BNType* type) {}
BINARYNINJACOREAPI bool BNFunctionHasUserType(BNFunction* func) { return {}; }
BINARYNINJACOREAPI char* BNGetFunctionComment(BNFunction* func) { return {}; }
BINARYNINJACOREAPI char* BNGetCommentForAddress(BNFunction* func,
                                                uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetCommentedAddresses(BNFunction* func,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAddressList(uint64_t* addrs) {}
BINARYNINJACOREAPI void BNSetFunctionComment(BNFunction* func,
                                             const char* comment) {}
BINARYNINJACOREAPI void BNSetCommentForAddress(BNFunction* func, uint64_t addr,
                                               const char* comment) {}
BINARYNINJACOREAPI void BNAddUserCodeReference(BNFunction* func,
                                               BNArchitecture* fromArch,
                                               uint64_t fromAddr,
                                               uint64_t toAddr) {}
BINARYNINJACOREAPI void BNRemoveUserCodeReference(BNFunction* func,
                                                  BNArchitecture* fromArch,
                                                  uint64_t fromAddr,
                                                  uint64_t toAddr) {}
BINARYNINJACOREAPI void BNAddUserTypeReference(BNFunction* func,
                                               BNArchitecture* fromArch,
                                               uint64_t fromAddr,
                                               BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNRemoveUserTypeReference(BNFunction* func,
                                                  BNArchitecture* fromArch,
                                                  uint64_t fromAddr,
                                                  BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNAddUserTypeFieldReference(
    BNFunction* func, BNArchitecture* fromArch, uint64_t fromAddr,
    BNQualifiedName* name, uint64_t offset, size_t size) {}
BINARYNINJACOREAPI void BNRemoveUserTypeFieldReference(
    BNFunction* func, BNArchitecture* fromArch, uint64_t fromAddr,
    BNQualifiedName* name, uint64_t offset, size_t size) {}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetForeignFunctionLiftedIL(
    const BNFunction* func, const BNLogger* logger,
    const size_t inlinedCallsCount, const uint64_t* inlinedCalls) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNNewBasicBlockReference(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBasicBlock(BNBasicBlock* block) {}
BINARYNINJACOREAPI BNLifterInstructionData* BNNewLifterInstructionDataReference(
    BNLifterInstructionData* instrData) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLifterInstructionData(
    BNLifterInstructionData* instrData) {}
BINARYNINJACOREAPI void BNLifterInstructionDataAppend(
    BNLifterInstructionData* instrData, BNBasicBlock* block, const void* data,
    size_t len) {}
BINARYNINJACOREAPI const uint8_t* BNLifterInstructionDataGet(
    BNLifterInstructionData* instrData, BNBasicBlock* block, uint64_t addr,
    size_t* len) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetFunctionBasicBlockList(BNFunction* func,
                                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBasicBlockList(BNBasicBlock** blocks,
                                             size_t count) {}
BINARYNINJACOREAPI BNBasicBlock* BNGetFunctionBasicBlockAtAddress(
    BNFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetRecentBasicBlockForAddress(
    BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlocksForAddress(BNBinaryView* view,
                                                             uint64_t addr,
                                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlocksStartingAtAddress(
    BNBinaryView* view, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetFunctionHighestAddress(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetFunctionLowestAddress(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNAddressRange* BNGetFunctionAddressRanges(BNFunction* func,
                                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetFunctionLowLevelIL(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetFunctionLowLevelILIfAvailable(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeILInstructionList(size_t* list) {}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetFunctionMediumLevelIL(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction*
BNGetFunctionMediumLevelILIfAvailable(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetFunctionMappedMediumLevelIL(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction*
BNGetFunctionMappedMediumLevelILIfAvailable(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetFunctionHighLevelIL(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetFunctionHighLevelILIfAvailable(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunction*
BNGetFunctionLanguageRepresentation(BNFunction* func, const char* language) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunction*
BNGetFunctionLanguageRepresentationIfAvailable(BNFunction* func,
                                               const char* language) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNGetConstantData(BNFunction* func,
                                                   BNRegisterValueType state,
                                                   uint64_t value, size_t size,
                                                   BNBuiltinType* builtin) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetRegisterValueAtInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetRegisterValueAfterInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue
BNGetStackContentsAtInstruction(BNFunction* func, BNArchitecture* arch,
                                uint64_t addr, int64_t offset, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue
BNGetStackContentsAfterInstruction(BNFunction* func, BNArchitecture* arch,
                                   uint64_t addr, int64_t offset, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetParameterValueAtInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, BNType* functionType,
    size_t i) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetParameterValueAtLowLevelILInstruction(
    BNFunction* func, size_t instr, BNType* functionType, size_t i) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetRegistersReadByInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetRegistersWrittenByInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNStackVariableReference*
BNGetStackVariablesReferencedByInstruction(BNFunction* func,
                                           BNArchitecture* arch, uint64_t addr,
                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNStackVariableReference*
BNGetStackVariablesReferencedByInstructionIfAvailable(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStackVariableReferenceList(
    BNStackVariableReference* refs, size_t count) {}
BINARYNINJACOREAPI BNConstantReference* BNGetConstantsReferencedByInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNConstantReference*
BNGetConstantsReferencedByInstructionIfAvailable(BNFunction* func,
                                                 BNArchitecture* arch,
                                                 uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeConstantReferenceList(BNConstantReference* refs) {
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetFunctionLiftedIL(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetFunctionLiftedILIfAvailable(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLiftedILFlagUsesForDefinition(BNFunction* func,
                                                              size_t i,
                                                              uint32_t flag,
                                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLiftedILFlagDefinitionsForUse(BNFunction* func,
                                                              size_t i,
                                                              uint32_t flag,
                                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetFlagsReadByLiftedILInstruction(
    BNFunction* func, size_t i, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetFlagsWrittenByLiftedILInstruction(
    BNFunction* func, size_t i, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetFunctionType(BNFunction* func) { return {}; }
BINARYNINJACOREAPI BNTypeWithConfidence
BNGetFunctionReturnType(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNReturnValue BNGetFunctionReturnValue(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeReturnValue(BNReturnValue* ret) {}
BINARYNINJACOREAPI bool BNIsFunctionReturnValueDefaultLocation(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNValueLocationWithConfidence
BNGetFunctionReturnValueLocation(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNRegisterSetWithConfidence
BNGetFunctionReturnRegisters(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNCallingConventionWithConfidence
BNGetFunctionCallingConvention(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNParameterVariablesWithConfidence
BNGetFunctionParameterVariables(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeParameterVariables(
    BNParameterVariablesWithConfidence* vars) {}
BINARYNINJACOREAPI BNValueLocationListWithConfidence
BNGetFunctionParameterLocations(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeParameterLocations(
    BNValueLocationListWithConfidence* locations) {}
BINARYNINJACOREAPI bool BNGetValueLocationVariableForReturnValue(
    const BNValueLocation* location, BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI bool BNGetValueLocationVariableForParameter(
    const BNValueLocation* location, BNVariable* var, size_t idx) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNFunctionHasVariableArguments(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNOffsetWithConfidence
BNGetFunctionStackAdjustment(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNRegisterStackAdjustment*
BNGetFunctionRegisterStackAdjustments(BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRegisterStackAdjustments(
    BNRegisterStackAdjustment* adjustments) {}
BINARYNINJACOREAPI BNRegisterSetWithConfidence
BNGetFunctionClobberedRegisters(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRegisterSet(BNRegisterSetWithConfidence* regs) {}
BINARYNINJACOREAPI void BNSetAutoFunctionReturnType(
    BNFunction* func, BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI void BNSetAutoIsFunctionReturnValueDefaultLocation(
    BNFunction* func, bool defaultLocation) {}
BINARYNINJACOREAPI void BNSetAutoFunctionReturnValueLocation(
    BNFunction* func, BNValueLocationWithConfidence* location) {}
BINARYNINJACOREAPI void BNSetAutoFunctionReturnValue(
    BNFunction* func, BNReturnValue* returnValue) {}
BINARYNINJACOREAPI void BNSetAutoFunctionCallingConvention(
    BNFunction* func, BNCallingConventionWithConfidence* convention) {}
BINARYNINJACOREAPI void BNSetAutoFunctionParameterLocations(
    BNFunction* func, BNValueLocationListWithConfidence* locations) {}
BINARYNINJACOREAPI void BNSetAutoFunctionHasVariableArguments(
    BNFunction* func, BNBoolWithConfidence* varArgs) {}
BINARYNINJACOREAPI void BNSetAutoFunctionCanReturn(
    BNFunction* func, BNBoolWithConfidence* returns) {}
BINARYNINJACOREAPI void BNSetAutoFunctionPure(BNFunction* func,
                                              BNBoolWithConfidence* pure) {}
BINARYNINJACOREAPI void BNSetAutoFunctionStackAdjustment(
    BNFunction* func, BNOffsetWithConfidence* stackAdjust) {}
BINARYNINJACOREAPI void BNSetAutoFunctionRegisterStackAdjustments(
    BNFunction* func, BNRegisterStackAdjustment* adjustments, size_t count) {}
BINARYNINJACOREAPI void BNSetAutoFunctionClobberedRegisters(
    BNFunction* func, BNRegisterSetWithConfidence* regs) {}
BINARYNINJACOREAPI void BNSetUserFunctionReturnType(
    BNFunction* func, BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI void BNSetUserIsFunctionReturnValueDefaultLocation(
    BNFunction* func, bool defaultLocation) {}
BINARYNINJACOREAPI void BNSetUserFunctionReturnValueLocation(
    BNFunction* func, BNValueLocationWithConfidence* location) {}
BINARYNINJACOREAPI void BNSetUserFunctionReturnValue(
    BNFunction* func, BNReturnValue* returnValue) {}
BINARYNINJACOREAPI void BNSetUserFunctionCallingConvention(
    BNFunction* func, BNCallingConventionWithConfidence* convention) {}
BINARYNINJACOREAPI void BNSetUserFunctionParameterLocations(
    BNFunction* func, BNValueLocationListWithConfidence* locations) {}
BINARYNINJACOREAPI void BNSetUserFunctionHasVariableArguments(
    BNFunction* func, BNBoolWithConfidence* varArgs) {}
BINARYNINJACOREAPI void BNSetUserFunctionCanReturn(
    BNFunction* func, BNBoolWithConfidence* returns) {}
BINARYNINJACOREAPI void BNSetUserFunctionPure(BNFunction* func,
                                              BNBoolWithConfidence* pure) {}
BINARYNINJACOREAPI void BNSetUserFunctionStackAdjustment(
    BNFunction* func, BNOffsetWithConfidence* stackAdjust) {}
BINARYNINJACOREAPI void BNSetUserFunctionRegisterStackAdjustments(
    BNFunction* func, BNRegisterStackAdjustment* adjustments, size_t count) {}
BINARYNINJACOREAPI void BNSetUserFunctionClobberedRegisters(
    BNFunction* func, BNRegisterSetWithConfidence* regs) {}
BINARYNINJACOREAPI void BNApplyImportedTypes(BNFunction* func, BNSymbol* sym,
                                             BNType* type) {}
BINARYNINJACOREAPI void BNApplyAutoDiscoveredFunctionType(BNFunction* func,
                                                          BNType* type) {}
BINARYNINJACOREAPI bool BNFunctionHasExplicitlyDefinedType(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNGetFunctionTypeTokens(
    BNFunction* func, BNDisassemblySettings* settings, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValueWithConfidenceAndRegister*
BNGetFunctionGlobalPointerValues(BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNFunctionUsesIncomingGlobalPointer(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValueWithConfidence
BNGetFunctionRegisterValueAtExit(BNFunction* func, uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNIsFunctionInlinedDuringAnalysis(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNInlineDuringAnalysisWithConfidence
BNGetFunctionInlinedDuringAnalysis(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNSetAutoFunctionInlinedDuringAnalysis(
    BNFunction* func, BNInlineDuringAnalysisWithConfidence inlined) {}
BINARYNINJACOREAPI void BNSetUserFunctionInlinedDuringAnalysis(
    BNFunction* func, BNInlineDuringAnalysisWithConfidence inlined) {}
BINARYNINJACOREAPI bool BNGetInstructionContainingAddress(BNFunction* func,
                                                          BNArchitecture* arch,
                                                          uint64_t addr,
                                                          uint64_t* start) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNGetBasicBlockFunction(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNGetBasicBlockArchitecture(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetBasicBlockSource(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetBasicBlockStart(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI void BNSetBasicBlockEnd(BNBasicBlock* block, uint64_t end) {}
BINARYNINJACOREAPI uint64_t BNGetBasicBlockEnd(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetBasicBlockLength(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlockEdge* BNGetBasicBlockOutgoingEdges(
    BNBasicBlock* block, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlockEdge* BNGetBasicBlockIncomingEdges(
    BNBasicBlock* block, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBasicBlockEdgeList(BNBasicBlockEdge* edges,
                                                 size_t count) {}
BINARYNINJACOREAPI bool BNBasicBlockHasUndeterminedOutgoingEdges(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI void BNBasicBlockAddPendingOutgoingEdge(BNBasicBlock* block,
                                                           BNBranchType type,
                                                           uint64_t addr,
                                                           BNArchitecture* arch,
                                                           bool fallThrough) {}
BINARYNINJACOREAPI BNPendingBasicBlockEdge* BNGetBasicBlockPendingOutgoingEdges(
    BNBasicBlock* block, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePendingBasicBlockEdgeList(
    BNPendingBasicBlockEdge* edges) {}
BINARYNINJACOREAPI void BNClearBasicBlockPendingOutgoingEdges(
    BNBasicBlock* block) {}
BINARYNINJACOREAPI void BNBasicBlockSetUndeterminedOutgoingEdges(
    BNBasicBlock* block, bool value) {}
BINARYNINJACOREAPI void BNBasicBlockSetFallThroughToFunction(
    BNBasicBlock* block, bool value) {}
BINARYNINJACOREAPI bool BNBasicBlockIsFallThroughToFunction(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI bool BNBasicBlockCanExit(BNBasicBlock* block) { return {}; }
BINARYNINJACOREAPI void BNBasicBlockSetCanExit(BNBasicBlock* block,
                                               bool value) {}
BINARYNINJACOREAPI void BNBasicBlockSetHasInvalidInstructions(
    BNBasicBlock* block, bool value) {}
BINARYNINJACOREAPI bool BNBasicBlockHasInvalidInstructions(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetBasicBlockIndex(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlockDominators(BNBasicBlock* block,
                                                            size_t* count,
                                                            bool post) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlockStrictDominators(
    BNBasicBlock* block, size_t* count, bool post) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetBasicBlockImmediateDominator(
    BNBasicBlock* block, bool post) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlockDominatorTreeChildren(
    BNBasicBlock* block, size_t* count, bool post) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlockDominanceFrontier(
    BNBasicBlock* block, size_t* count, bool post) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetBasicBlockIteratedDominanceFrontier(
    BNBasicBlock** blocks, size_t incomingCount, size_t* outputCount) {
  return {};
}
BINARYNINJACOREAPI bool BNIsILBasicBlock(BNBasicBlock* block) { return {}; }
BINARYNINJACOREAPI bool BNIsLowLevelILBasicBlock(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMediumLevelILBasicBlock(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI bool BNIsHighLevelILBasicBlock(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNFunctionGraphType
BNGetBasicBlockFunctionGraphType(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetBasicBlockLowLevelILFunction(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction*
BNGetBasicBlockMediumLevelILFunction(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetBasicBlockHighLevelILFunction(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI bool BNGetBasicBlockInstructionContainingAddress(
    BNBasicBlock* block, uint64_t addr, uint64_t* start) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetBasicBlockSourceBlock(
    BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNGetBasicBlockDisassemblyText(
    BNBasicBlock* block, BNDisassemblySettings* settings, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDisassemblyTextLines(BNDisassemblyTextLine* lines,
                                                   size_t count) {}
BINARYNINJACOREAPI char* BNGetDisplayStringForInteger(BNBinaryView* binaryView,
                                                      BNIntegerDisplayType type,
                                                      uint64_t value,
                                                      size_t inputWidth,
                                                      bool isSigned) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextRenderer* BNCreateDisassemblyTextRenderer(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextRenderer*
BNCreateLowLevelILDisassemblyTextRenderer(BNLowLevelILFunction* func,
                                          BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextRenderer*
BNCreateMediumLevelILDisassemblyTextRenderer(BNMediumLevelILFunction* func,
                                             BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextRenderer*
BNCreateHighLevelILDisassemblyTextRenderer(BNHighLevelILFunction* func,
                                           BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextRenderer*
BNNewDisassemblyTextRendererReference(BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDisassemblyTextRenderer(
    BNDisassemblyTextRenderer* renderer) {}
BINARYNINJACOREAPI BNFunction* BNGetDisassemblyTextRendererFunction(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction*
BNGetDisassemblyTextRendererLowLevelILFunction(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction*
BNGetDisassemblyTextRendererMediumLevelILFunction(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction*
BNGetDisassemblyTextRendererHighLevelILFunction(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetDisassemblyTextRendererBasicBlock(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNGetDisassemblyTextRendererArchitecture(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblySettings* BNGetDisassemblyTextRendererSettings(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyTextRendererBasicBlock(
    BNDisassemblyTextRenderer* renderer, BNBasicBlock* block) {}
BINARYNINJACOREAPI void BNSetDisassemblyTextRendererArchitecture(
    BNDisassemblyTextRenderer* renderer, BNArchitecture* arch) {}
BINARYNINJACOREAPI void BNSetDisassemblyTextRendererSettings(
    BNDisassemblyTextRenderer* renderer, BNDisassemblySettings* settings) {}
BINARYNINJACOREAPI bool BNIsILDisassemblyTextRenderer(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI bool BNDisassemblyTextRendererHasDataFlow(
    BNDisassemblyTextRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken*
BNGetDisassemblyTextRendererInstructionAnnotations(
    BNDisassemblyTextRenderer* renderer, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetDisassemblyTextRendererInstructionText(
    BNDisassemblyTextRenderer* renderer, uint64_t addr, size_t* len,
    BNDisassemblyTextLine** result, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetDisassemblyTextRendererLines(
    BNDisassemblyTextRenderer* renderer, uint64_t addr, size_t* len,
    BNDisassemblyTextLine** result, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine*
BNPostProcessDisassemblyTextRendererLines(BNDisassemblyTextRenderer* renderer,
                                          uint64_t addr, size_t len,
                                          BNDisassemblyTextLine* inLines,
                                          size_t inCount, size_t* outCount,
                                          const char* indentSpaces) {
  return {};
}
BINARYNINJACOREAPI void BNResetDisassemblyTextRendererDeduplicatedComments(
    BNDisassemblyTextRenderer* renderer) {}
BINARYNINJACOREAPI bool BNGetDisassemblyTextRendererSymbolTokens(
    BNDisassemblyTextRenderer* renderer, uint64_t addr, size_t size,
    size_t operand, BNInstructionTextToken** result, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSymbolDisplayResult
BNGetDisassemblyTextRendererSymbolTokensStatic(
    uint64_t addr, size_t size, size_t operand, BNBinaryView* data,
    size_t maxSymbolWidth, BNFunction* func, uint8_t confidence,
    BNSymbolDisplayType symbolDisplay, BNOperatorPrecedence precedence,
    uint64_t instrAddr, uint64_t exprIndex, BNInstructionTextToken** result,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken*
BNGetDisassemblyTextRendererStackVariableReferenceTokens(
    BNDisassemblyTextRenderer* renderer, BNStackVariableReference* ref,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNIsIntegerToken(BNInstructionTextTokenType type) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken*
BNGetDisassemblyTextRendererIntegerTokens(BNDisassemblyTextRenderer* renderer,
                                          BNInstructionTextToken* token,
                                          BNArchitecture* arch, uint64_t addr,
                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNDisassemblyTextRendererWrapComment(
    BNDisassemblyTextRenderer* renderer, const BNDisassemblyTextLine* inLine,
    size_t* outLineCount, const char* comment, bool hasAutoAnnotations,
    const char* leadingSpaces, const char* indentSpaces) {
  return {};
}
BINARYNINJACOREAPI char* BNGetStringLiteralPrefix(BNStringType type) {
  return {};
}
BINARYNINJACOREAPI void BNMarkFunctionAsRecentlyUsed(BNFunction* func) {}
BINARYNINJACOREAPI void BNMarkBasicBlockAsRecentlyUsed(BNBasicBlock* block) {}
BINARYNINJACOREAPI BNReferenceSource* BNGetCodeReferences(BNBinaryView* view,
                                                          uint64_t addr,
                                                          size_t* count,
                                                          bool limit,
                                                          size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI BNReferenceSource* BNGetCodeReferencesInRange(
    BNBinaryView* view, uint64_t addr, uint64_t len, size_t* count, bool limit,
    size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCodeReferences(BNReferenceSource* refs,
                                             size_t count) {}
BINARYNINJACOREAPI void BNFreeTypeFieldReferences(BNTypeFieldReference* refs,
                                                  size_t count) {}
BINARYNINJACOREAPI void BNFreeILReferences(BNILReferenceSource* refs,
                                           size_t count) {}
BINARYNINJACOREAPI uint64_t* BNGetCodeReferencesFrom(BNBinaryView* view,
                                                     BNReferenceSource* src,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetCodeReferencesFromInRange(
    BNBinaryView* view, BNReferenceSource* src, uint64_t len, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferences(BNBinaryView* view,
                                                 uint64_t addr, size_t* count,
                                                 bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferencesInRange(
    BNBinaryView* view, uint64_t addr, uint64_t len, size_t* count, bool limit,
    size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferencesFrom(BNBinaryView* view,
                                                     uint64_t addr,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferencesFromInRange(BNBinaryView* view,
                                                            uint64_t addr,
                                                            uint64_t len,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddDataReference(BNBinaryView* view,
                                           uint64_t fromAddr, uint64_t toAddr) {
}
BINARYNINJACOREAPI void BNRemoveDataReference(BNBinaryView* view,
                                              uint64_t fromAddr,
                                              uint64_t toAddr) {}
BINARYNINJACOREAPI void BNAddUserDataReference(BNBinaryView* view,
                                               uint64_t fromAddr,
                                               uint64_t toAddr) {}
BINARYNINJACOREAPI void BNRemoveUserDataReference(BNBinaryView* view,
                                                  uint64_t fromAddr,
                                                  uint64_t toAddr) {}
BINARYNINJACOREAPI void BNFreeDataReferences(uint64_t* refs) {}
BINARYNINJACOREAPI void BNFreeTypeReferences(BNTypeReferenceSource* refs,
                                             size_t count) {}
BINARYNINJACOREAPI void BNFreeTypeFieldReferenceSizeInfo(
    BNTypeFieldReferenceSizeInfo* refs, size_t count) {}
BINARYNINJACOREAPI void BNFreeTypeFieldReferenceTypeInfo(
    BNTypeFieldReferenceTypeInfo* refs, size_t count) {}
BINARYNINJACOREAPI void BNFreeTypeFieldReferenceSizes(size_t* refs,
                                                      size_t count) {}
BINARYNINJACOREAPI void BNFreeTypeFieldReferenceTypes(
    BNTypeWithConfidence* refs, size_t count) {}
BINARYNINJACOREAPI BNReferenceSource* BNGetCodeReferencesForType(
    BNBinaryView* view, BNQualifiedName* type, size_t* count, bool limit,
    size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferencesForType(BNBinaryView* view,
                                                        BNQualifiedName* type,
                                                        size_t* count,
                                                        bool limit,
                                                        size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI BNTypeReferenceSource* BNGetTypeReferencesForType(
    BNBinaryView* view, BNQualifiedName* type, size_t* count, bool limit,
    size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI BNTypeFieldReference* BNGetCodeReferencesForTypeField(
    BNBinaryView* view, BNQualifiedName* type, uint64_t offset, size_t* count,
    bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferencesForTypeField(
    BNBinaryView* view, BNQualifiedName* type, uint64_t offset, size_t* count,
    bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetDataReferencesFromForTypeField(
    BNBinaryView* view, BNQualifiedName* type, uint64_t offset, size_t* count,
    bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI BNTypeReferenceSource* BNGetTypeReferencesForTypeField(
    BNBinaryView* view, BNQualifiedName* type, uint64_t offset, size_t* count,
    bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI BNAllTypeReferences BNGetAllReferencesForType(
    BNBinaryView* view, BNQualifiedName* type, bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAllTypeReferences(BNAllTypeReferences* refs) {}
BINARYNINJACOREAPI BNAllTypeFieldReferences
BNGetAllReferencesForTypeField(BNBinaryView* view, BNQualifiedName* type,
                               uint64_t offset, bool limit, size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAllTypeFieldReferences(
    BNAllTypeFieldReferences* refs) {}
BINARYNINJACOREAPI BNTypeReferenceSource* BNGetCodeReferencesForTypeFrom(
    BNBinaryView* view, BNReferenceSource* addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeReferenceSource* BNGetCodeReferencesForTypeFromInRange(
    BNBinaryView* view, BNReferenceSource* addr, uint64_t len, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeReferenceSource* BNGetCodeReferencesForTypeFieldsFrom(
    BNBinaryView* view, BNReferenceSource* addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeReferenceSource*
BNGetCodeReferencesForTypeFieldsFromInRange(BNBinaryView* view,
                                            BNReferenceSource* addr,
                                            uint64_t len, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetAllFieldsReferenced(BNBinaryView* view,
                                                      BNQualifiedName* type,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeFieldReferenceSizeInfo* BNGetAllSizesReferenced(
    BNBinaryView* view, BNQualifiedName* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeFieldReferenceTypeInfo* BNGetAllTypesReferenced(
    BNBinaryView* view, BNQualifiedName* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetSizesReferenced(BNBinaryView* view,
                                                BNQualifiedName* type,
                                                uint64_t offset,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeWithConfidence* BNGetTypesReferenced(
    BNBinaryView* view, BNQualifiedName* type, uint64_t offset, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName* BNGetOutgoingDirectTypeReferences(
    BNBinaryView* view, BNQualifiedName* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName* BNGetOutgoingRecursiveTypeReferences(
    BNBinaryView* view, BNQualifiedName* types, size_t typeCount,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName* BNGetIncomingDirectTypeReferences(
    BNBinaryView* view, BNQualifiedName* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName* BNGetIncomingRecursiveTypeReferences(
    BNBinaryView* view, BNQualifiedName* types, size_t typeCount,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterGlobalFunctionRecognizer(
    BNFunctionRecognizer* rec) {}
BINARYNINJACOREAPI bool BNGetStringAtAddress(BNBinaryView* view, uint64_t addr,
                                             BNStringReference* strRef) {
  return {};
}
BINARYNINJACOREAPI BNStringReference* BNGetStrings(BNBinaryView* view,
                                                   size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNStringReference* BNGetStringsInRange(BNBinaryView* view,
                                                          uint64_t start,
                                                          uint64_t len,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStringReferenceList(BNStringReference* strings) {}
BINARYNINJACOREAPI BNStringDetector* BNCreateStringDetector(
    const BNStringDetectionParameters* params) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStringDetector(BNStringDetector* detector) {}
BINARYNINJACOREAPI BNStringReference* BNStringDetectorDetectStrings(
    BNStringDetector* detector, const uint8_t* data, size_t dataLen,
    size_t blockLen, uint64_t baseAddress, BNStringReference* lastFoundString,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDerivedString* BNGetDerivedStrings(BNBinaryView* view,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNReferenceSource* BNGetDerivedStringCodeReferences(
    BNBinaryView* view, BNDerivedString* str, size_t* count, bool limit,
    size_t maxItems) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDerivedStringList(BNDerivedString* strings,
                                                size_t count) {}
BINARYNINJACOREAPI BNVariableNameAndType* BNGetStackLayout(BNFunction* func,
                                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeVariableNameAndTypeList(
    BNVariableNameAndType* vars, size_t count) {}
BINARYNINJACOREAPI void BNCreateAutoStackVariable(BNFunction* func,
                                                  int64_t offset,
                                                  BNTypeWithConfidence* type,
                                                  const char* name) {}
BINARYNINJACOREAPI void BNCreateUserStackVariable(BNFunction* func,
                                                  int64_t offset,
                                                  BNTypeWithConfidence* type,
                                                  const char* name) {}
BINARYNINJACOREAPI void BNDeleteAutoStackVariable(BNFunction* func,
                                                  int64_t offset) {}
BINARYNINJACOREAPI void BNDeleteUserStackVariable(BNFunction* func,
                                                  int64_t offset) {}
BINARYNINJACOREAPI bool BNGetStackVariableAtFrameOffset(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, int64_t offset,
    BNVariableNameAndType* var) {
  return {};
}
BINARYNINJACOREAPI bool BNGetStackVariableAtFrameOffsetAfterInstruction(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, int64_t offset,
    BNVariableNameAndType* var) {
  return {};
}
BINARYNINJACOREAPI void BNFreeVariableNameAndType(BNVariableNameAndType* var) {}
BINARYNINJACOREAPI BNVariableNameAndType* BNGetFunctionVariables(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNCreateAutoVariable(BNFunction* func,
                                             const BNVariable* var,
                                             BNTypeWithConfidence* type,
                                             const char* name,
                                             bool ignoreDisjointUses) {}
BINARYNINJACOREAPI void BNCreateUserVariable(BNFunction* func,
                                             const BNVariable* var,
                                             BNTypeWithConfidence* type,
                                             const char* name,
                                             bool ignoreDisjointUses) {}
BINARYNINJACOREAPI void BNDeleteUserVariable(BNFunction* func,
                                             const BNVariable* var) {}
BINARYNINJACOREAPI bool BNIsVariableUserDefined(BNFunction* func,
                                                const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI BNTypeWithConfidence
BNGetVariableType(BNFunction* func, const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI char* BNGetVariableName(BNFunction* func,
                                           const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI char* BNGetVariableNameOrDefault(BNFunction* func,
                                                    const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI char* BNGetLastSeenVariableNameOrDefault(
    BNFunction* func, const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNToVariableIdentifier(const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI BNVariable BNFromVariableIdentifier(uint64_t id) {
  return {};
}
BINARYNINJACOREAPI BNDeadStoreElimination
BNGetFunctionVariableDeadStoreElimination(BNFunction* func,
                                          const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI void BNSetFunctionVariableDeadStoreElimination(
    BNFunction* func, const BNVariable* var, BNDeadStoreElimination mode) {}
BINARYNINJACOREAPI BNExprFolding BNGetExprFolding(BNFunction* func,
                                                  uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNSetExprFolding(BNFunction* func, uint64_t addr,
                                         BNExprFolding mode) {}
BINARYNINJACOREAPI bool BNIsConditionInverted(BNFunction* func, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNSetConditionInverted(BNFunction* func, uint64_t addr,
                                               bool invert) {}
BINARYNINJACOREAPI BNEarlyReturn BNGetEarlyReturn(BNFunction* func,
                                                  uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNSetEarlyReturn(BNFunction* func, uint64_t addr,
                                         BNEarlyReturn mode) {}
BINARYNINJACOREAPI BNSwitchRecovery BNGetSwitchRecovery(BNFunction* func,
                                                        uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNSetSwitchRecovery(BNFunction* func, uint64_t addr,
                                            BNSwitchRecovery mode) {}
BINARYNINJACOREAPI BNMergedVariable* BNGetMergedVariables(BNFunction* func,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeMergedVariableList(BNMergedVariable* vars,
                                                 size_t count) {}
BINARYNINJACOREAPI void BNMergeVariables(BNFunction* func,
                                         const BNVariable* target,
                                         const BNVariable* sources,
                                         size_t sourceCount) {}
BINARYNINJACOREAPI void BNUnmergeVariables(BNFunction* func,
                                           const BNVariable* target,
                                           const BNVariable* sources,
                                           size_t sourceCount) {}
BINARYNINJACOREAPI BNVariable* BNGetSplitVariables(BNFunction* func,
                                                   size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSplitVariable(BNFunction* func,
                                        const BNVariable* var) {}
BINARYNINJACOREAPI void BNUnsplitVariable(BNFunction* func,
                                          const BNVariable* var) {}
BINARYNINJACOREAPI BNReferenceSource* BNGetFunctionCallSites(BNFunction* func,
                                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNGetCallees(BNBinaryView* view,
                                          BNReferenceSource* callSite,
                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNReferenceSource* BNGetCallers(BNBinaryView* view,
                                                   uint64_t callee,
                                                   size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSetAutoIndirectBranches(
    BNFunction* func, BNArchitecture* sourceArch, uint64_t source,
    BNArchitectureAndAddress* branches, size_t count) {}
BINARYNINJACOREAPI void BNSetUserIndirectBranches(
    BNFunction* func, BNArchitecture* sourceArch, uint64_t source,
    BNArchitectureAndAddress* branches, size_t count) {}
BINARYNINJACOREAPI void BNSetGuidedSourceBlocks(
    BNFunction* func, BNArchitectureAndAddress* addresses, size_t count) {}
BINARYNINJACOREAPI void BNAddGuidedSourceBlocks(
    BNFunction* func, BNArchitectureAndAddress* addresses, size_t count) {}
BINARYNINJACOREAPI void BNRemoveGuidedSourceBlocks(
    BNFunction* func, BNArchitectureAndAddress* addresses, size_t count) {}
BINARYNINJACOREAPI bool BNIsGuidedSourceBlock(BNFunction* func,
                                              BNArchitecture* arch,
                                              uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNArchitectureAndAddress* BNGetGuidedSourceBlocks(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNHasGuidedSourceBlocks(BNFunction* func) { return {}; }
BINARYNINJACOREAPI void BNFreeArchitectureAndAddressList(
    BNArchitectureAndAddress* addresses) {}
BINARYNINJACOREAPI BNIndirectBranchInfo* BNGetIndirectBranches(BNFunction* func,
                                                               size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNIndirectBranchInfo* BNGetIndirectBranchesAt(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeIndirectBranchList(
    BNIndirectBranchInfo* branches) {}
BINARYNINJACOREAPI BNFunction* BNGetCalleeForAnalysis(BNFunction* func,
                                                      BNPlatform* platform,
                                                      uint64_t addr,
                                                      bool exact) {
  return {};
}
BINARYNINJACOREAPI BNArchitectureAndAddress* BNGetUnresolvedIndirectBranches(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNHasUnresolvedIndirectBranches(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFunctionToggleRegion(BNFunction* func,
                                               uint64_t hash) {}
BINARYNINJACOREAPI bool BNFunctionIsRegionCollapsed(BNFunction* func,
                                                    uint64_t hash) {
  return {};
}
BINARYNINJACOREAPI void BNFunctionExpandAll(BNFunction* func) {}
BINARYNINJACOREAPI void BNFunctionCollapseRegion(BNFunction* func,
                                                 uint64_t hash) {}
BINARYNINJACOREAPI void BNFunctionExpandRegion(BNFunction* func,
                                               uint64_t hash) {}
BINARYNINJACOREAPI void BNFunctionStoreMetadata(BNFunction* func,
                                                const char* key,
                                                BNMetadata* value,
                                                BNMetadataStoreFlag flags) {}
BINARYNINJACOREAPI BNMetadata* BNFunctionQueryMetadata(BNFunction* func,
                                                       const char* key) {
  return {};
}
BINARYNINJACOREAPI void BNFunctionRemoveMetadata(BNFunction* func,
                                                 const char* key) {}
BINARYNINJACOREAPI BNMetadata* BNFunctionGetMetadata(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNFunctionGetAutoMetadata(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNSetAutoCallTypeAdjustment(
    BNFunction* func, BNArchitecture* arch, uint64_t addr,
    BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI void BNSetUserCallTypeAdjustment(
    BNFunction* func, BNArchitecture* arch, uint64_t addr,
    BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI void BNSetAutoCallStackAdjustment(BNFunction* func,
                                                     BNArchitecture* arch,
                                                     uint64_t addr,
                                                     int64_t adjust,
                                                     uint8_t confidence) {}
BINARYNINJACOREAPI void BNSetUserCallStackAdjustment(BNFunction* func,
                                                     BNArchitecture* arch,
                                                     uint64_t addr,
                                                     int64_t adjust,
                                                     uint8_t confidence) {}
BINARYNINJACOREAPI void BNSetAutoCallRegisterStackAdjustment(
    BNFunction* func, BNArchitecture* arch, uint64_t addr,
    BNRegisterStackAdjustment* adjust, size_t count) {}
BINARYNINJACOREAPI void BNSetUserCallRegisterStackAdjustment(
    BNFunction* func, BNArchitecture* arch, uint64_t addr,
    BNRegisterStackAdjustment* adjust, size_t count) {}
BINARYNINJACOREAPI void BNSetAutoCallRegisterStackAdjustmentForRegisterStack(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, uint32_t regStack,
    int32_t adjust, uint8_t confidence) {}
BINARYNINJACOREAPI void BNSetUserCallRegisterStackAdjustmentForRegisterStack(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, uint32_t regStack,
    int32_t adjust, uint8_t confidence) {}
BINARYNINJACOREAPI BNTypeWithConfidence
BNGetCallTypeAdjustment(BNFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNOffsetWithConfidence BNGetCallStackAdjustment(
    BNFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterStackAdjustment* BNGetCallRegisterStackAdjustment(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterStackAdjustment
BNGetCallRegisterStackAdjustmentForRegisterStack(BNFunction* func,
                                                 BNArchitecture* arch,
                                                 uint64_t addr,
                                                 uint32_t regStack) {
  return {};
}
BINARYNINJACOREAPI bool BNIsCallInstruction(BNFunction* func,
                                            BNArchitecture* arch,
                                            uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextLine* BNGetFunctionBlockAnnotations(
    BNFunction* func, BNArchitecture* arch, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetFunctionBlockSortHint(BNFunction* func,
                                                   BNArchitecture* arch,
                                                   uint64_t addr,
                                                   int64_t* result) {
  return {};
}
BINARYNINJACOREAPI BNIntegerDisplayType BNGetIntegerConstantDisplayType(
    BNFunction* func, BNArchitecture* arch, uint64_t instrAddr, uint64_t value,
    size_t operand) {
  return {};
}
BINARYNINJACOREAPI void BNSetIntegerConstantDisplayType(
    BNFunction* func, BNArchitecture* arch, uint64_t instrAddr, uint64_t value,
    size_t operand, BNIntegerDisplayType type, const char* typeID) {}
BINARYNINJACOREAPI char* BNGetIntegerConstantDisplayTypeEnumerationType(
    BNFunction* func, BNArchitecture* arch, uint64_t instrAddr, uint64_t value,
    size_t operand) {
  return {};
}
BINARYNINJACOREAPI bool BNIsFunctionTooLarge(BNFunction* func) { return {}; }
BINARYNINJACOREAPI bool BNIsFunctionAnalysisSkipped(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisSkipReason
BNGetAnalysisSkipReason(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNFunctionAnalysisSkipOverride
BNGetFunctionAnalysisSkipOverride(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNSetFunctionAnalysisSkipOverride(
    BNFunction* func, BNFunctionAnalysisSkipOverride skip) {}
BINARYNINJACOREAPI char* BNGetGotoLabelName(BNFunction* func,
                                            uint64_t labelId) {
  return {};
}
BINARYNINJACOREAPI void BNSetUserGotoLabelName(BNFunction* func,
                                               uint64_t labelId,
                                               const char* name) {}
BINARYNINJACOREAPI BNBasicBlock* BNAnalyzeBasicBlocksContextCreateBasicBlock(
    BNBasicBlockAnalysisContext* abb, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNAnalyzeBasicBlocksContextAddBasicBlockToFunction(
    BNBasicBlockAnalysisContext* abb, BNBasicBlock* block) {}
BINARYNINJACOREAPI void BNAnalyzeBasicBlocksContextAddTempReference(
    BNBasicBlockAnalysisContext* abb, BNFunction* target) {}
BINARYNINJACOREAPI void BNAnalyzeBasicBlocksContextSetDirectCodeReferences(
    BNBasicBlockAnalysisContext* abb, BNArchitectureAndAddress* sources,
    uint64_t* targets, size_t count) {}
BINARYNINJACOREAPI void BNAnalyzeBasicBlocksContextSetDirectNoReturnCalls(
    BNBasicBlockAnalysisContext* abb, BNArchitectureAndAddress* sources,
    size_t count) {}
BINARYNINJACOREAPI void BNAnalyzeBasicBlocksContextSetContextualFunctionReturns(
    BNBasicBlockAnalysisContext* abb, BNArchitectureAndAddress* sources,
    bool* values, size_t count) {}
BINARYNINJACOREAPI void
BNAnalyzeBasicBlocksContextSetHaltedDisassemblyAddresses(
    BNBasicBlockAnalysisContext* abb, BNArchitectureAndAddress* sources,
    size_t count) {}
BINARYNINJACOREAPI void
BNAnalyzeBasicBlocksContextSetInlinedUnresolvedIndirectBranches(
    BNBasicBlockAnalysisContext* abb, BNArchitectureAndAddress* locations,
    size_t count) {}
BINARYNINJACOREAPI BNAnalysisParameters
BNGetParametersForAnalysis(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetParametersForAnalysis(
    BNBinaryView* view, BNAnalysisParameters params) {}
BINARYNINJACOREAPI uint64_t
BNGetMaxFunctionSizeForAnalysis(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetMaxFunctionSizeForAnalysis(BNBinaryView* view,
                                                        uint64_t size) {}
BINARYNINJACOREAPI bool BNGetNewAutoFunctionAnalysisSuppressed(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSetNewAutoFunctionAnalysisSuppressed(
    BNBinaryView* view, bool suppress) {}
BINARYNINJACOREAPI BNAnalysisCompletionEvent* BNAddAnalysisCompletionEvent(
    BNBinaryView* view, void* ctxt, void (*callback)(void* ctxt)) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisCompletionEvent*
BNNewAnalysisCompletionEventReference(BNAnalysisCompletionEvent* event) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAnalysisCompletionEvent(
    BNAnalysisCompletionEvent* event) {}
BINARYNINJACOREAPI void BNCancelAnalysisCompletionEvent(
    BNAnalysisCompletionEvent* event) {}
BINARYNINJACOREAPI bool BNShouldSkipTargetAnalysis(
    BNBinaryView* view, BNArchitectureAndAddress* source,
    BNFunction* sourceFunc, uint64_t sourceEnd,
    BNArchitectureAndAddress* target) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisInfo* BNGetAnalysisInfo(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAnalysisInfo(BNAnalysisInfo* info) {}
BINARYNINJACOREAPI BNAnalysisProgress
BNGetAnalysisProgress(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisState BNGetAnalysisState(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNBackgroundTask* BNGetBackgroundAnalysisTask(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetNextFunctionStartAfterAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetNextBasicBlockStartAfterAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetNextDataAfterAddress(BNBinaryView* view,
                                                      uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetNextDataVariableStartAfterAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetPreviousFunctionStartBeforeAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetPreviousBasicBlockStartBeforeAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetPreviousBasicBlockEndBeforeAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetPreviousDataBeforeAddress(BNBinaryView* view,
                                                           uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetPreviousDataVariableStartBeforeAddress(BNBinaryView* view, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewDisassembly(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewLiftedIL(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewLowLevelIL(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewLowLevelILSSAForm(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewMediumLevelIL(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewMediumLevelILSSAForm(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewMappedMediumLevelIL(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewMappedMediumLevelILSSAForm(BNBinaryView* view,
                                             BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewHighLevelIL(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewHighLevelILSSAForm(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewLanguageRepresentation(
    BNBinaryView* view, BNDisassemblySettings* settings, const char* language) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewDataOnly(
    BNBinaryView* view, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionDisassembly(BNFunction* func,
                                            BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNCreateLinearViewSingleFunctionLiftedIL(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionLowLevelIL(BNFunction* func,
                                           BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionLowLevelILSSAForm(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionMediumLevelIL(BNFunction* func,
                                              BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionMediumLevelILSSAForm(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionMappedMediumLevelIL(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionMappedMediumLevelILSSAForm(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionHighLevelIL(BNFunction* func,
                                            BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionHighLevelILSSAForm(
    BNFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNCreateLinearViewSingleFunctionLanguageRepresentation(
    BNFunction* func, BNDisassemblySettings* settings, const char* language) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNNewLinearViewObjectReference(
    BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLinearViewObject(BNLinearViewObject* obj) {}
BINARYNINJACOREAPI BNLinearViewObject* BNGetFirstLinearViewObjectChild(
    BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNGetLastLinearViewObjectChild(
    BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNGetPreviousLinearViewObjectChild(
    BNLinearViewObject* parent, BNLinearViewObject* child) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNGetNextLinearViewObjectChild(
    BNLinearViewObject* parent, BNLinearViewObject* child) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNGetLinearViewObjectChildForAddress(
    BNLinearViewObject* parent, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNGetLinearViewObjectChildForIdentifier(
    BNLinearViewObject* parent, BNLinearViewObjectIdentifier* id) {
  return {};
}
BINARYNINJACOREAPI BNLinearDisassemblyLine* BNGetLinearViewObjectLines(
    BNLinearViewObject* obj, BNLinearViewObject* prev, BNLinearViewObject* next,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLinearDisassemblyLines(
    BNLinearDisassemblyLine* lines, size_t count) {}
BINARYNINJACOREAPI uint64_t
BNGetLinearViewObjectStart(BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetLinearViewObjectEnd(BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObjectIdentifier
BNGetLinearViewObjectIdentifier(BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLinearViewObjectIdentifier(
    BNLinearViewObjectIdentifier* id) {}
BINARYNINJACOREAPI int BNCompareLinearViewObjectChildren(
    BNLinearViewObject* obj, BNLinearViewObject* a, BNLinearViewObject* b) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetLinearViewObjectOrderingIndexTotal(BNLinearViewObject* obj) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetLinearViewObjectOrderingIndexForChild(
    BNLinearViewObject* parent, BNLinearViewObject* child) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject*
BNGetLinearViewObjectChildForOrderingIndex(BNLinearViewObject* parent,
                                           uint64_t idx) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewCursor* BNCreateLinearViewCursor(
    BNLinearViewObject* root) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewCursor* BNDuplicateLinearViewCursor(
    BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewCursor* BNNewLinearViewCursorReference(
    BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLinearViewCursor(BNLinearViewCursor* cursor) {}
BINARYNINJACOREAPI bool BNIsLinearViewCursorBeforeBegin(
    BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI bool BNIsLinearViewCursorAfterEnd(
    BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObject* BNGetLinearViewCursorCurrentObject(
    BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI BNLinearViewObjectIdentifier* BNGetLinearViewCursorPath(
    BNLinearViewCursor* cursor, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLinearViewCursorPath(
    BNLinearViewObjectIdentifier* objs, size_t count) {}
BINARYNINJACOREAPI BNLinearViewObject** BNGetLinearViewCursorPathObjects(
    BNLinearViewCursor* cursor, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLinearViewCursorPathObjects(
    BNLinearViewObject** objs, size_t count) {}
BINARYNINJACOREAPI BNAddressRange
BNGetLinearViewCursorOrderingIndex(BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetLinearViewCursorOrderingIndexTotal(BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI void BNSeekLinearViewCursorToBegin(
    BNLinearViewCursor* cursor) {}
BINARYNINJACOREAPI void BNSeekLinearViewCursorToEnd(
    BNLinearViewCursor* cursor) {}
BINARYNINJACOREAPI void BNSeekLinearViewCursorToAddress(
    BNLinearViewCursor* cursor, uint64_t addr) {}
BINARYNINJACOREAPI bool BNSeekLinearViewCursorToPath(
    BNLinearViewCursor* cursor, BNLinearViewObjectIdentifier* ids,
    size_t count) {
  return {};
}
BINARYNINJACOREAPI bool BNSeekLinearViewCursorToPathAndAddress(
    BNLinearViewCursor* cursor, BNLinearViewObjectIdentifier* ids, size_t count,
    uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI bool BNSeekLinearViewCursorToCursorPath(
    BNLinearViewCursor* cursor, BNLinearViewCursor* path) {
  return {};
}
BINARYNINJACOREAPI bool BNSeekLinearViewCursorToCursorPathAndAddress(
    BNLinearViewCursor* cursor, BNLinearViewCursor* path, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNSeekLinearViewCursorToOrderingIndex(
    BNLinearViewCursor* cursor, uint64_t idx) {}
BINARYNINJACOREAPI bool BNLinearViewCursorNext(BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI bool BNLinearViewCursorPrevious(BNLinearViewCursor* cursor) {
  return {};
}
BINARYNINJACOREAPI BNLinearDisassemblyLine* BNGetLinearViewCursorLines(
    BNLinearViewCursor* cursor, size_t* count) {
  return {};
}
BINARYNINJACOREAPI int BNCompareLinearViewCursors(BNLinearViewCursor* a,
                                                  BNLinearViewCursor* b) {
  return {};
}
BINARYNINJACOREAPI BNRenderLayer** BNGetLinearViewCursorRenderLayers(
    BNLinearViewCursor* cursor, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddLinearViewCursorRenderLayer(
    BNLinearViewCursor* cursor, BNRenderLayer* layer) {}
BINARYNINJACOREAPI void BNRemoveLinearViewCursorRenderLayer(
    BNLinearViewCursor* cursor, BNRenderLayer* layer) {}
BINARYNINJACOREAPI void BNDefineDataVariable(BNBinaryView* view, uint64_t addr,
                                             BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI void BNDefineUserDataVariable(BNBinaryView* view,
                                                 uint64_t addr,
                                                 BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI void BNUndefineDataVariable(BNBinaryView* view,
                                               uint64_t addr, bool blacklist) {}
BINARYNINJACOREAPI void BNUndefineUserDataVariable(BNBinaryView* view,
                                                   uint64_t addr) {}
BINARYNINJACOREAPI BNDataVariable* BNGetDataVariables(BNBinaryView* view,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDataVariable(BNDataVariable* var) {}
BINARYNINJACOREAPI void BNFreeDataVariables(BNDataVariable* vars,
                                            size_t count) {}
BINARYNINJACOREAPI void BNFreeDataVariableAndName(BNDataVariableAndName* var) {}
BINARYNINJACOREAPI void BNFreeDataVariablesAndName(BNDataVariableAndName* vars,
                                                   size_t count) {}
BINARYNINJACOREAPI void BNFreeDataVariableAndNameAndDebugParserList(
    BNDataVariableAndNameAndDebugParser* vars, size_t count) {}
BINARYNINJACOREAPI bool BNGetDataVariableAtAddress(BNBinaryView* view,
                                                   uint64_t addr,
                                                   BNDataVariable* var) {
  return {};
}
BINARYNINJACOREAPI bool BNParseTypeString(
    BNBinaryView* view, const char* text, BNQualifiedNameAndType* result,
    char** errors, BNQualifiedNameList* typesAllowRedefinition,
    bool importDepencencies) {
  return {};
}
BINARYNINJACOREAPI bool BNParseTypesString(
    BNBinaryView* view, const char* text, const char* const* options,
    size_t optionCount, const char* const* includeDirs, size_t includeDirCount,
    BNTypeParserResult* result, char** errors,
    BNQualifiedNameList* typesAllowRedefinition, bool importDepencencies) {
  return {};
}
BINARYNINJACOREAPI void BNFreeQualifiedNameAndType(
    BNQualifiedNameAndType* obj) {}
BINARYNINJACOREAPI void BNFreeQualifiedNameAndTypeArray(
    BNQualifiedNameAndType* obj, size_t count) {}
BINARYNINJACOREAPI void BNFreeQualifiedNameTypeAndId(
    BNQualifiedNameTypeAndId* obj) {}
BINARYNINJACOREAPI char* BNEscapeTypeName(const char* name,
                                          BNTokenEscapingType escaping) {
  return {};
}
BINARYNINJACOREAPI char* BNUnescapeTypeName(const char* name,
                                            BNTokenEscapingType escaping) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType* BNGetAnalysisTypeList(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType*
BNGetAnalysisDependencySortedTypeList(BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeAndNameList(BNQualifiedNameAndType* types,
                                              size_t count) {}
BINARYNINJACOREAPI void BNFreeTypeIdList(BNQualifiedNameTypeAndId* types,
                                         size_t count) {}
BINARYNINJACOREAPI BNQualifiedName* BNGetAnalysisTypeNames(
    BNBinaryView* view, size_t* count, const char* matching) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeNameList(BNQualifiedName* names,
                                           size_t count) {}
BINARYNINJACOREAPI BNTypeContainer* BNGetAnalysisTypeContainer(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainer* BNGetAnalysisAutoTypeContainer(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainer* BNGetAnalysisUserTypeContainer(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetAnalysisTypeByName(BNBinaryView* view,
                                                   BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetAnalysisTypeByRef(BNBinaryView* view,
                                                  BNNamedTypeReference* ref) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetAnalysisTypeById(BNBinaryView* view,
                                                 const char* id) {
  return {};
}
BINARYNINJACOREAPI char* BNGetAnalysisTypeId(BNBinaryView* view,
                                             BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName BNGetAnalysisTypeNameById(BNBinaryView* view,
                                                             const char* id) {
  return {};
}
BINARYNINJACOREAPI bool BNIsAnalysisTypeAutoDefined(BNBinaryView* view,
                                                    BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName
BNDefineAnalysisType(BNBinaryView* view, const char* id,
                     BNQualifiedName* defaultName, BNType* type) {
  return {};
}
BINARYNINJACOREAPI void BNDefineUserAnalysisType(BNBinaryView* view,
                                                 BNQualifiedName* name,
                                                 BNType* type) {}
BINARYNINJACOREAPI size_t BNDefineAnalysisTypes(
    BNBinaryView* view, BNQualifiedNameTypeAndId* types, size_t count,
    BNProgressFunction progress, void* progressContext, char*** resultIds,
    BNQualifiedName** resultNames) {
  return {};
}
BINARYNINJACOREAPI void BNDefineUserAnalysisTypes(BNBinaryView* view,
                                                  BNQualifiedNameAndType* types,
                                                  size_t count,
                                                  BNProgressFunction progress,
                                                  void* progressContext) {}
BINARYNINJACOREAPI void BNUndefineAnalysisType(BNBinaryView* view,
                                               const char* id) {}
BINARYNINJACOREAPI void BNUndefineUserAnalysisType(BNBinaryView* view,
                                                   BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNRenameAnalysisType(BNBinaryView* view,
                                             BNQualifiedName* oldName,
                                             BNQualifiedName* newName) {}
BINARYNINJACOREAPI BNType* BNGetAnalysisSystemCallType(BNBinaryView* view,
                                                       BNPlatform* platform,
                                                       uint32_t id) {
  return {};
}
BINARYNINJACOREAPI char* BNGetAnalysisSystemCallName(BNBinaryView* view,
                                                     BNPlatform* platform,
                                                     uint32_t id) {
  return {};
}
BINARYNINJACOREAPI char* BNGenerateAutoTypeId(const char* source,
                                              BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGenerateAutoPlatformTypeId(BNPlatform* platform,
                                                      BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGenerateAutoDemangledTypeId(BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetAutoPlatformTypeIdSource(BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI char* BNGetAutoDemangledTypeIdSource(void) { return {}; }
BINARYNINJACOREAPI char* BNGenerateAutoDebugTypeId(BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetAutoDebugTypeIdSource(void) { return {}; }
BINARYNINJACOREAPI void BNRegisterPlatformTypes(BNBinaryView* view,
                                                BNPlatform* platform) {}
BINARYNINJACOREAPI bool BNLookupImportedTypePlatform(
    BNBinaryView* view, const BNQualifiedName* typeName, BNPlatform** platform,
    BNQualifiedName* resultName) {
  return {};
}
BINARYNINJACOREAPI void BNReanalyzeAllFunctions(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNAnalyzeFunction(BNFunction* func) {}
BINARYNINJACOREAPI void BNReanalyzeFunction(BNFunction* func,
                                            BNFunctionUpdateType type) {}
BINARYNINJACOREAPI void BNMarkUpdatesRequired(BNFunction* func,
                                              BNFunctionUpdateType type) {}
BINARYNINJACOREAPI void BNMarkCallerUpdatesRequired(BNFunction* func,
                                                    BNFunctionUpdateType type) {
}
BINARYNINJACOREAPI BNHighlightColor BNGetInstructionHighlight(
    BNFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNSetAutoInstructionHighlight(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      BNHighlightColor color) {}
BINARYNINJACOREAPI void BNSetUserInstructionHighlight(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      BNHighlightColor color) {}
BINARYNINJACOREAPI BNHighlightColor
BNGetBasicBlockHighlight(BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI void BNSetAutoBasicBlockHighlight(BNBasicBlock* block,
                                                     BNHighlightColor color) {}
BINARYNINJACOREAPI void BNSetUserBasicBlockHighlight(BNBasicBlock* block,
                                                     BNHighlightColor color) {}
BINARYNINJACOREAPI void BNFreeTypeContainer(BNTypeContainer* container) {}
BINARYNINJACOREAPI BNTypeContainer* BNDuplicateTypeContainer(
    BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeContainerGetId(BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeContainerGetName(BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainerType
BNTypeContainerGetType(BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerIsMutable(BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNTypeContainerGetPlatform(
    BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerAddTypes(
    BNTypeContainer* container, const BNQualifiedName* typeNames,
    BNType** types, size_t typeCount, BNProgressFunction progress,
    void* progressContext, BNQualifiedName** resultNames, char*** resultIds,
    size_t* resultCount) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerRenameType(
    BNTypeContainer* container, const char* typeId,
    const BNQualifiedName* newName) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerDeleteType(BNTypeContainer* container,
                                                  const char* typeId) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeId(
    BNTypeContainer* container, const BNQualifiedName* typeName,
    char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeName(BNTypeContainer* container,
                                                   const char* typeId,
                                                   BNQualifiedName* result) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeById(BNTypeContainer* container,
                                                   const char* typeId,
                                                   BNType** result) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypes(BNTypeContainer* container,
                                                char*** typeIds,
                                                BNQualifiedName** typeNames,
                                                BNType*** types,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeByName(
    BNTypeContainer* container, const BNQualifiedName* typeName,
    BNType** result) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeIds(BNTypeContainer* container,
                                                  char*** typeIds,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeNames(BNTypeContainer* container,
                                                    BNQualifiedName** typeNames,
                                                    size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerGetTypeNamesAndIds(
    BNTypeContainer* container, char*** typeIds, BNQualifiedName** typeNames,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t
BNTypeContainerGetTypeCount(BNTypeContainer* container) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerParseTypeString(
    BNTypeContainer* container, const char* source, bool importDepencencies,
    BNQualifiedNameAndType* result, BNTypeParserError** errors,
    size_t* errorCount) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeContainerParseTypesFromSource(
    BNTypeContainer* container, const char* source, const char* fileName,
    const char* const* options, size_t optionCount,
    const char* const* includeDirs, size_t includeDirCount,
    const char* autoTypeSource, bool importDepencencies,
    BNTypeParserResult* result, BNTypeParserError** errors,
    size_t* errorCount) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainer* BNGetEmptyTypeContainer() { return {}; }
BINARYNINJACOREAPI BNTagType* BNCreateTagType(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI BNTagType* BNNewTagTypeReference(BNTagType* tagType) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTagType(BNTagType* tagType) {}
BINARYNINJACOREAPI void BNFreeTagTypeList(BNTagType** tagTypes, size_t count) {}
BINARYNINJACOREAPI BNBinaryView* BNTagTypeGetView(BNTagType* tagType) {
  return {};
}
BINARYNINJACOREAPI char* BNTagTypeGetId(BNTagType* tagType) { return {}; }
BINARYNINJACOREAPI char* BNTagTypeGetName(BNTagType* tagType) { return {}; }
BINARYNINJACOREAPI void BNTagTypeSetName(BNTagType* tagType, const char* name) {
}
BINARYNINJACOREAPI char* BNTagTypeGetIcon(BNTagType* tagType) { return {}; }
BINARYNINJACOREAPI void BNTagTypeSetIcon(BNTagType* tagType, const char* icon) {
}
BINARYNINJACOREAPI bool BNTagTypeGetVisible(BNTagType* tagType) { return {}; }
BINARYNINJACOREAPI void BNTagTypeSetVisible(BNTagType* tagType, bool visible) {}
BINARYNINJACOREAPI BNTagTypeType BNTagTypeGetType(BNTagType* tagType) {
  return {};
}
BINARYNINJACOREAPI void BNTagTypeSetType(BNTagType* tagType,
                                         BNTagTypeType type) {}
BINARYNINJACOREAPI BNTag* BNCreateTag(BNTagType* type, const char* data) {
  return {};
}
BINARYNINJACOREAPI BNTag* BNNewTagReference(BNTag* tag) { return {}; }
BINARYNINJACOREAPI void BNFreeTag(BNTag* tag) {}
BINARYNINJACOREAPI void BNFreeTagList(BNTag** tags, size_t count) {}
BINARYNINJACOREAPI char* BNTagGetId(BNTag* tag) { return {}; }
BINARYNINJACOREAPI BNTagType* BNTagGetType(BNTag* tag) { return {}; }
BINARYNINJACOREAPI char* BNTagGetData(BNTag* tag) { return {}; }
BINARYNINJACOREAPI void BNTagSetData(BNTag* tag, const char* data) {}
BINARYNINJACOREAPI void BNAddTagType(BNBinaryView* view, BNTagType* tagType) {}
BINARYNINJACOREAPI void BNRemoveTagType(BNBinaryView* view,
                                        BNTagType* tagType) {}
BINARYNINJACOREAPI BNTagType* BNGetTagType(BNBinaryView* view,
                                           const char* name) {
  return {};
}
BINARYNINJACOREAPI BNTagType* BNGetTagTypeWithType(BNBinaryView* view,
                                                   const char* name,
                                                   BNTagTypeType type) {
  return {};
}
BINARYNINJACOREAPI BNTagType* BNGetTagTypeById(BNBinaryView* view,
                                               const char* id) {
  return {};
}
BINARYNINJACOREAPI BNTagType* BNGetTagTypeByIdWithType(BNBinaryView* view,
                                                       const char* id,
                                                       BNTagTypeType type) {
  return {};
}
BINARYNINJACOREAPI BNTagType** BNGetTagTypes(BNBinaryView* view,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddTag(BNBinaryView* view, BNTag* tag, bool user) {}
BINARYNINJACOREAPI BNTag* BNGetTag(BNBinaryView* view, const char* tagId) {
  return {};
}
BINARYNINJACOREAPI void BNRemoveTag(BNBinaryView* view, BNTag* tag, bool user) {
}
BINARYNINJACOREAPI BNTagReference* BNGetAllTagReferences(BNBinaryView* view,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAllAddressTagReferences(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAllFunctionTagReferences(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAllTagReferencesOfType(
    BNBinaryView* view, BNTagType* tagType, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetTagReferencesOfType(BNBinaryView* view,
                                                            BNTagType* tagType,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetDataTagReferences(BNBinaryView* view,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAutoDataTagReferences(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetUserDataTagReferences(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNRemoveTagReference(BNBinaryView* view,
                                             BNTagReference ref) {}
BINARYNINJACOREAPI void BNFreeTagReferences(BNTagReference* refs,
                                            size_t count) {}
BINARYNINJACOREAPI BNTag** BNGetDataTags(BNBinaryView* view, uint64_t addr,
                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAutoDataTags(BNBinaryView* view, uint64_t addr,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetUserDataTags(BNBinaryView* view, uint64_t addr,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetDataTagsOfType(BNBinaryView* view,
                                               uint64_t addr,
                                               BNTagType* tagType,
                                               size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAutoDataTagsOfType(BNBinaryView* view,
                                                   uint64_t addr,
                                                   BNTagType* tagType,
                                                   size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetUserDataTagsOfType(BNBinaryView* view,
                                                   uint64_t addr,
                                                   BNTagType* tagType,
                                                   size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetDataTagsInRange(BNBinaryView* view,
                                                        uint64_t start,
                                                        uint64_t end,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAutoDataTagsInRange(BNBinaryView* view,
                                                            uint64_t start,
                                                            uint64_t end,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetUserDataTagsInRange(BNBinaryView* view,
                                                            uint64_t start,
                                                            uint64_t end,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddAutoDataTag(BNBinaryView* view, uint64_t addr,
                                         BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveAutoDataTag(BNBinaryView* view, uint64_t addr,
                                            BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveAutoDataTagsOfType(BNBinaryView* view,
                                                   uint64_t addr,
                                                   BNTagType* tagType) {}
BINARYNINJACOREAPI void BNAddUserDataTag(BNBinaryView* view, uint64_t addr,
                                         BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveUserDataTag(BNBinaryView* view, uint64_t addr,
                                            BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveUserDataTagsOfType(BNBinaryView* view,
                                                   uint64_t addr,
                                                   BNTagType* tagType) {}
BINARYNINJACOREAPI size_t BNGetTagReferencesOfTypeCount(BNBinaryView* view,
                                                        BNTagType* tagType) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetAllTagReferencesOfTypeCount(BNBinaryView* view,
                                                           BNTagType* tagType) {
  return {};
}
BINARYNINJACOREAPI void BNGetAllTagReferenceTypeCounts(BNBinaryView* view,
                                                       BNTagType*** tagTypes,
                                                       size_t** counts,
                                                       size_t* count) {}
BINARYNINJACOREAPI void BNFreeTagReferenceTypeCounts(BNTagType** tagTypes,
                                                     size_t* counts,
                                                     size_t count) {}
BINARYNINJACOREAPI BNTagReference* BNGetFunctionAllTagReferences(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetFunctionTagReferencesOfType(
    BNFunction* func, BNTagType* tagType, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAddressTagReferences(BNFunction* func,
                                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAutoAddressTagReferences(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetUserAddressTagReferences(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAddressTags(BNFunction* func,
                                            BNArchitecture* arch, uint64_t addr,
                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAutoAddressTags(BNFunction* func,
                                                BNArchitecture* arch,
                                                uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetUserAddressTags(BNFunction* func,
                                                BNArchitecture* arch,
                                                uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAddressTagsOfType(BNFunction* func,
                                                  BNArchitecture* arch,
                                                  uint64_t addr,
                                                  BNTagType* tagType,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAutoAddressTagsOfType(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      BNTagType* tagType,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetUserAddressTagsOfType(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      BNTagType* tagType,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAddressTagsInRange(BNFunction* func,
                                                           BNArchitecture* arch,
                                                           uint64_t start,
                                                           uint64_t end,
                                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAutoAddressTagsInRange(
    BNFunction* func, BNArchitecture* arch, uint64_t start, uint64_t end,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetUserAddressTagsInRange(
    BNFunction* func, BNArchitecture* arch, uint64_t start, uint64_t end,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddAutoAddressTag(BNFunction* func,
                                            BNArchitecture* arch, uint64_t addr,
                                            BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveAutoAddressTag(BNFunction* func,
                                               BNArchitecture* arch,
                                               uint64_t addr, BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveAutoAddressTagsOfType(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      BNTagType* tagType) {}
BINARYNINJACOREAPI void BNAddUserAddressTag(BNFunction* func,
                                            BNArchitecture* arch, uint64_t addr,
                                            BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveUserAddressTag(BNFunction* func,
                                               BNArchitecture* arch,
                                               uint64_t addr, BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveUserAddressTagsOfType(BNFunction* func,
                                                      BNArchitecture* arch,
                                                      uint64_t addr,
                                                      BNTagType* tagType) {}
BINARYNINJACOREAPI BNTagReference* BNGetFunctionTagReferences(BNFunction* func,
                                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetAutoFunctionTagReferences(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTagReference* BNGetUserFunctionTagReferences(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetFunctionTags(BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAutoFunctionTags(BNFunction* func,
                                                 size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetUserFunctionTags(BNFunction* func,
                                                 size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetFunctionTagsOfType(BNFunction* func,
                                                   BNTagType* tagType,
                                                   size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetAutoFunctionTagsOfType(BNFunction* func,
                                                       BNTagType* tagType,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTag** BNGetUserFunctionTagsOfType(BNFunction* func,
                                                       BNTagType* tagType,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddAutoFunctionTag(BNFunction* func, BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveAutoFunctionTag(BNFunction* func, BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveAutoFunctionTagsOfType(BNFunction* func,
                                                       BNTagType* tagType) {}
BINARYNINJACOREAPI void BNAddUserFunctionTag(BNFunction* func, BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveUserFunctionTag(BNFunction* func, BNTag* tag) {}
BINARYNINJACOREAPI void BNRemoveUserFunctionTagsOfType(BNFunction* func,
                                                       BNTagType* tagType) {}
BINARYNINJACOREAPI BNPerformanceInfo* BNGetFunctionAnalysisPerformanceInfo(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAnalysisPerformanceInfo(BNPerformanceInfo* info,
                                                      size_t count) {}
BINARYNINJACOREAPI BNFlowGraph* BNGetUnresolvedStackAdjustmentGraph(
    BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNSetUserVariableValue(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite, bool after,
    const BNPossibleValueSet* value) {}
BINARYNINJACOREAPI void BNClearUserVariableValue(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite, bool after) {}
BINARYNINJACOREAPI BNUserVariableValue* BNGetAllUserVariableValues(
    BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUserVariableValues(BNUserVariableValue* result) {}
BINARYNINJACOREAPI bool BNParsePossibleValueSet(BNBinaryView* view,
                                                const char* valueText,
                                                BNRegisterValueType state,
                                                BNPossibleValueSet* result,
                                                uint64_t here, char** errors) {
  return {};
}
BINARYNINJACOREAPI void BNCreateForcedVariableVersion(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite) {}
BINARYNINJACOREAPI void BNClearForcedVariableVersion(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite) {}
BINARYNINJACOREAPI void BNSetFieldResolutionForVariableAt(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite,
    const BNFieldResolutionInfo* info) {}
BINARYNINJACOREAPI BNFieldResolutionInfo* BNGetFieldResolutionForVariableAt(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite) {
  return {};
}
BINARYNINJACOREAPI BNVariableFieldResolutionInfo*
BNGetAllVariableFieldResolutions(BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeVariableFieldResolutions(
    BNVariableFieldResolutionInfo* result, size_t count) {}
BINARYNINJACOREAPI void BNClearFieldResolutionForVariableAt(
    BNFunction* func, const BNVariable* var,
    const BNArchitectureAndAddress* defSite) {}
BINARYNINJACOREAPI void BNRequestFunctionDebugReport(BNFunction* func,
                                                     const char* name) {}
BINARYNINJACOREAPI bool BNFunctionCheckForDebugReport(BNFunction* func,
                                                      const char* name) {
  return {};
}
BINARYNINJACOREAPI BNILReferenceSource* BNGetMediumLevelILVariableReferences(
    BNFunction* func, BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetMediumLevelILVariableReferencesFrom(BNFunction* func, BNArchitecture* arch,
                                         uint64_t address, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetMediumLevelILVariableReferencesInRange(BNFunction* func,
                                            BNArchitecture* arch,
                                            uint64_t address, uint64_t len,
                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNILReferenceSource*
BNGetMediumLevelILVariableReferencesIfAvailable(BNFunction* func,
                                                BNVariable* var,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetMediumLevelILVariableReferencesFromIfAvailable(BNFunction* func,
                                                    BNArchitecture* arch,
                                                    uint64_t address,
                                                    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetMediumLevelILVariableReferencesInRangeIfAvailable(BNFunction* func,
                                                       BNArchitecture* arch,
                                                       uint64_t address,
                                                       uint64_t len,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNILReferenceSource* BNGetHighLevelILVariableReferences(
    BNFunction* func, BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetHighLevelILVariableReferencesFrom(BNFunction* func, BNArchitecture* arch,
                                       uint64_t address, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetHighLevelILVariableReferencesInRange(BNFunction* func,
                                          BNArchitecture* arch,
                                          uint64_t address, uint64_t len,
                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNILReferenceSource*
BNGetHighLevelILVariableReferencesIfAvailable(BNFunction* func, BNVariable* var,
                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetHighLevelILVariableReferencesFromIfAvailable(BNFunction* func,
                                                  BNArchitecture* arch,
                                                  uint64_t address,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariableReferenceSource*
BNGetHighLevelILVariableReferencesInRangeIfAvailable(BNFunction* func,
                                                     BNArchitecture* arch,
                                                     uint64_t address,
                                                     uint64_t len,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeVariableList(BNVariable* vars) {}
BINARYNINJACOREAPI void BNFreeVariableReferenceSourceList(
    BNVariableReferenceSource* vars, size_t count) {}
BINARYNINJACOREAPI BNAnalysisContext* BNCreateAnalysisContext(void) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisContext* BNNewAnalysisContextReference(
    BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAnalysisContext(
    BNAnalysisContext* analysisContext) {}
BINARYNINJACOREAPI BNBinaryView* BNAnalysisContextGetBinaryView(
    BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNAnalysisContextGetFunction(
    BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNAnalysisContextGetLiftedILFunction(
    BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNAnalysisContextGetLowLevelILFunction(
    BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction*
BNAnalysisContextGetMediumLevelILFunction(BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction*
BNAnalysisContextGetHighLevelILFunction(BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI void BNSetBasicBlockList(BNAnalysisContext* analysisContext,
                                            BNBasicBlock** basicBlocks,
                                            size_t count) {}
BINARYNINJACOREAPI void BNSetLiftedILFunction(
    BNAnalysisContext* analysisContext, BNLowLevelILFunction* liftedIL) {}
BINARYNINJACOREAPI void BNSetLowLevelILFunction(
    BNAnalysisContext* analysisContext, BNLowLevelILFunction* lowLevelIL) {}
BINARYNINJACOREAPI void BNSetMediumLevelILFunction(
    BNAnalysisContext* analysisContext, BNMediumLevelILFunction* mediumLevelIL,
    size_t* llilSSAToMLILSSAInstrMap, size_t instrCount,
    BNExprMapInfo* llilSSAToMLILSSAExprMap, size_t exprCount) {}
BINARYNINJACOREAPI void BNSetHighLevelILFunction(
    BNAnalysisContext* analysisContext, BNHighLevelILFunction* highLevelIL) {}
BINARYNINJACOREAPI bool BNAnalysisContextInform(
    BNAnalysisContext* analysisContext, const char* request) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextGetSettingBool(
    BNAnalysisContext* analysisContext, const char* key) {
  return {};
}
BINARYNINJACOREAPI double BNAnalysisContextGetSettingDouble(
    BNAnalysisContext* analysisContext, const char* key) {
  return {};
}
BINARYNINJACOREAPI int64_t BNAnalysisContextGetSettingInt64(
    BNAnalysisContext* analysisContext, const char* key) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNAnalysisContextGetSettingUInt64(
    BNAnalysisContext* analysisContext, const char* key) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisContextGetSettingString(
    BNAnalysisContext* analysisContext, const char* key) {
  return {};
}
BINARYNINJACOREAPI char** BNAnalysisContextGetSettingStringList(
    BNAnalysisContext* analysisContext, const char* key, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsValidOffset(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetReadable(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetWritable(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetExecutable(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetBackedByFile(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetCodeSemantics(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetExternSemantics(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetWritableSemantics(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisContextIsOffsetReadOnlySemantics(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI BNSection** BNAnalysisContextGetSections(
    BNAnalysisContext* analysisContext, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSection* BNAnalysisContextGetSectionByName(
    BNAnalysisContext* analysisContext, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNSection** BNAnalysisContextGetSectionsAt(
    BNAnalysisContext* analysisContext, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNAnalysisContextGetStart(BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNAnalysisContextGetEnd(BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNAnalysisContextGetLength(BNAnalysisContext* analysisContext) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNAnalysisContextGetNextValidOffset(
    BNAnalysisContext* analysisContext, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNAnalysisContextGetNextMappedAddress(
    BNAnalysisContext* analysisContext, uint64_t addr, uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNAnalysisContextGetNextBackedAddress(
    BNAnalysisContext* analysisContext, uint64_t addr, uint32_t flags) {
  return {};
}
BINARYNINJACOREAPI BNSegment* BNAnalysisContextGetSegmentAt(
    BNAnalysisContext* analysisContext, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNAddressRange* BNAnalysisContextGetMappedAddressRanges(
    BNAnalysisContext* analysisContext, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNAddressRange* BNAnalysisContextGetBackedAddressRanges(
    BNAnalysisContext* analysisContext, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNActivity* BNCreateActivity(
    const char* configuration, void* ctxt,
    void (*action)(void*, BNAnalysisContext*)) {
  return {};
}
BINARYNINJACOREAPI BNActivity* BNCreateActivityWithEligibility(
    const char* configuration, void* ctxt,
    void (*action)(void*, BNAnalysisContext*),
    bool (*eligibilityHandler)(void*, BNActivity*, BNAnalysisContext*)) {
  return {};
}
BINARYNINJACOREAPI BNActivity* BNNewActivityReference(BNActivity* activity) {
  return {};
}
BINARYNINJACOREAPI void BNFreeActivity(BNActivity* activity) {}
BINARYNINJACOREAPI char* BNActivityGetName(BNActivity* activity) { return {}; }
BINARYNINJACOREAPI BNWorkflow* BNCreateWorkflow(const char* name) { return {}; }
BINARYNINJACOREAPI BNWorkflow* BNNewWorkflowReference(BNWorkflow* workflow) {
  return {};
}
BINARYNINJACOREAPI void BNFreeWorkflow(BNWorkflow* workflow) {}
BINARYNINJACOREAPI BNWorkflow** BNGetWorkflowList(size_t* count) { return {}; }
BINARYNINJACOREAPI void BNFreeWorkflowList(BNWorkflow** workflows,
                                           size_t count) {}
BINARYNINJACOREAPI BNWorkflow* BNWorkflowGet(const char* name) { return {}; }
BINARYNINJACOREAPI BNWorkflow* BNWorkflowGetOrCreate(const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNRegisterWorkflow(BNWorkflow* workflow,
                                           const char* configuration) {
  return {};
}
BINARYNINJACOREAPI BNWorkflow* BNWorkflowClone(BNWorkflow* workflow,
                                               const char* name,
                                               const char* activity) {
  return {};
}
BINARYNINJACOREAPI BNActivity* BNWorkflowRegisterActivity(
    BNWorkflow* workflow, BNActivity* activity, const char** subactivities,
    size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNWorkflowContains(BNWorkflow* workflow,
                                           const char* activity) {
  return {};
}
BINARYNINJACOREAPI char* BNWorkflowGetConfiguration(BNWorkflow* workflow,
                                                    const char* activity) {
  return {};
}
BINARYNINJACOREAPI char* BNGetWorkflowName(BNWorkflow* workflow) { return {}; }
BINARYNINJACOREAPI bool BNWorkflowIsRegistered(BNWorkflow* workflow) {
  return {};
}
BINARYNINJACOREAPI size_t BNWorkflowSize(BNWorkflow* workflow) { return {}; }
BINARYNINJACOREAPI BNActivity* BNWorkflowGetActivity(BNWorkflow* workflow,
                                                     const char* activity) {
  return {};
}
BINARYNINJACOREAPI const char** BNWorkflowGetActivityRoots(BNWorkflow* workflow,
                                                           const char* activity,
                                                           size_t* inoutSize) {
  return {};
}
BINARYNINJACOREAPI const char** BNWorkflowGetSubactivities(BNWorkflow* workflow,
                                                           const char* activity,
                                                           bool immediate,
                                                           size_t* inoutSize) {
  return {};
}
BINARYNINJACOREAPI bool BNWorkflowAssignSubactivities(BNWorkflow* workflow,
                                                      const char* activity,
                                                      const char** activities,
                                                      size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNWorkflowClear(BNWorkflow* workflow) { return {}; }
BINARYNINJACOREAPI bool BNWorkflowInsert(BNWorkflow* workflow,
                                         const char* activity,
                                         const char** activities, size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNWorkflowInsertAfter(BNWorkflow* workflow,
                                              const char* activity,
                                              const char** activities,
                                              size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNWorkflowRemove(BNWorkflow* workflow,
                                         const char* activity) {
  return {};
}
BINARYNINJACOREAPI bool BNWorkflowReplace(BNWorkflow* workflow,
                                          const char* activity,
                                          const char* newActivity) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNWorkflowGetGraph(BNWorkflow* workflow,
                                                   const char* activity,
                                                   bool sequential) {
  return {};
}
BINARYNINJACOREAPI void BNWorkflowShowReport(BNWorkflow* workflow,
                                             const char* name) {}
BINARYNINJACOREAPI const char** BNWorkflowGetEligibilitySettings(
    BNWorkflow* workflow, size_t* inoutSize) {
  return {};
}
BINARYNINJACOREAPI BNWorkflow* BNGetWorkflowForBinaryView(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI char* BNPostWorkflowRequestForBinaryView(
    BNBinaryView* view, const char* request) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNGetWorkflowGraphForBinaryView(
    BNBinaryView* view, const char* name, bool sequential) {
  return {};
}
BINARYNINJACOREAPI void BNShowWorkflowReportForBinaryView(BNBinaryView* view,
                                                          const char* name) {}
BINARYNINJACOREAPI BNWorkflow* BNGetWorkflowForFunction(BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI char* BNPostWorkflowRequestForFunction(BNFunction* func,
                                                          const char* request) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNGetWorkflowGraphForFunction(BNFunction* func,
                                                              const char* name,
                                                              bool sequential) {
  return {};
}
BINARYNINJACOREAPI void BNShowWorkflowReportForFunction(BNFunction* func,
                                                        const char* name) {}
BINARYNINJACOREAPI char* BNGetProvenanceString(BNFunction* func) { return {}; }
BINARYNINJACOREAPI BNDisassemblySettings* BNCreateDisassemblySettings(void) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblySettings* BNDefaultDisassemblySettings(void) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblySettings* BNDefaultGraphDisassemblySettings(
    void) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblySettings* BNDefaultLinearDisassemblySettings(
    void) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblySettings* BNNewDisassemblySettingsReference(
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblySettings* BNDuplicateDisassemblySettings(
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDisassemblySettings(
    BNDisassemblySettings* settings) {}
BINARYNINJACOREAPI bool BNIsDisassemblySettingsOptionSet(
    BNDisassemblySettings* settings, BNDisassemblyOption option) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblySettingsOption(
    BNDisassemblySettings* settings, BNDisassemblyOption option, bool state) {}
BINARYNINJACOREAPI size_t
BNGetDisassemblyWidth(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyWidth(BNDisassemblySettings* settings,
                                              size_t width) {}
BINARYNINJACOREAPI size_t
BNGetDisassemblyMaximumSymbolWidth(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyMaximumSymbolWidth(
    BNDisassemblySettings* settings, size_t width) {}
BINARYNINJACOREAPI size_t
BNGetDisassemblyGutterWidth(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyGutterWidth(
    BNDisassemblySettings* settings, size_t width) {}
BINARYNINJACOREAPI BNDisassemblyAddressMode
BNGetDisassemblyAddressMode(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyAddressMode(
    BNDisassemblySettings* settings, BNDisassemblyAddressMode mode) {}
BINARYNINJACOREAPI uint64_t
BNGetDisassemblyAddressBaseOffset(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyAddressBaseOffset(
    BNDisassemblySettings* settings, uint64_t addressBaseOffset) {}
BINARYNINJACOREAPI BNDisassemblyCallParameterHints
BNGetDisassemblyCallParameterHints(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyCallParameterHints(
    BNDisassemblySettings* settings, BNDisassemblyCallParameterHints hints) {}
BINARYNINJACOREAPI BNDisassemblyBlockLabels
BNGetDisassemblyBlockLabels(BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNSetDisassemblyBlockLabels(
    BNDisassemblySettings* settings, BNDisassemblyBlockLabels labels) {}
BINARYNINJACOREAPI BNFlowGraph* BNCreateFlowGraph(void) { return {}; }
BINARYNINJACOREAPI BNFlowGraph* BNCreateFunctionGraph(
    BNFunction* func, BNFunctionViewType type,
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateLowLevelILFunctionGraph(
    BNLowLevelILFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateMediumLevelILFunctionGraph(
    BNMediumLevelILFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateHighLevelILFunctionGraph(
    BNHighLevelILFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateImmediateFunctionGraph(
    BNFunction* func, BNFunctionViewType type,
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateLowLevelILImmediateFunctionGraph(
    BNLowLevelILFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateMediumLevelILImmediateFunctionGraph(
    BNMediumLevelILFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateHighLevelILImmediateFunctionGraph(
    BNHighLevelILFunction* func, BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNCreateCustomFlowGraph(
    BNCustomFlowGraph* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNNewFlowGraphReference(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlowGraph(BNFlowGraph* graph) {}
BINARYNINJACOREAPI BNFunction* BNGetFunctionForFlowGraph(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI void BNSetFunctionForFlowGraph(BNFlowGraph* graph,
                                                  BNFunction* func) {}
BINARYNINJACOREAPI BNBinaryView* BNGetViewForFlowGraph(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI void BNSetViewForFlowGraph(BNFlowGraph* graph,
                                              BNBinaryView* view) {}
BINARYNINJACOREAPI int BNGetHorizontalFlowGraphNodeMargin(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI int BNGetVerticalFlowGraphNodeMargin(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI void BNSetFlowGraphNodeMargins(BNFlowGraph* graph, int horiz,
                                                  int vert) {}
BINARYNINJACOREAPI BNFlowGraphLayoutRequest* BNStartFlowGraphLayout(
    BNFlowGraph* graph, void* ctxt, void (*func)(void* ctxt)) {
  return {};
}
BINARYNINJACOREAPI bool BNIsFlowGraphLayoutComplete(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraphLayoutRequest*
BNNewFlowGraphLayoutRequestReference(BNFlowGraphLayoutRequest* layout) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlowGraphLayoutRequest(
    BNFlowGraphLayoutRequest* layout) {}
BINARYNINJACOREAPI bool BNIsFlowGraphLayoutRequestComplete(
    BNFlowGraphLayoutRequest* layout) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNGetGraphForFlowGraphLayoutRequest(
    BNFlowGraphLayoutRequest* layout) {
  return {};
}
BINARYNINJACOREAPI void BNAbortFlowGraphLayoutRequest(
    BNFlowGraphLayoutRequest* graph) {}
BINARYNINJACOREAPI bool BNIsILFlowGraph(BNFlowGraph* graph) { return {}; }
BINARYNINJACOREAPI bool BNIsLowLevelILFlowGraph(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMediumLevelILFlowGraph(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI bool BNIsHighLevelILFlowGraph(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetFlowGraphLowLevelILFunction(
    BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetFlowGraphMediumLevelILFunction(
    BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetFlowGraphHighLevelILFunction(
    BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI void BNSetFlowGraphLowLevelILFunction(
    BNFlowGraph* graph, BNLowLevelILFunction* func) {}
BINARYNINJACOREAPI void BNSetFlowGraphMediumLevelILFunction(
    BNFlowGraph* graph, BNMediumLevelILFunction* func) {}
BINARYNINJACOREAPI void BNSetFlowGraphHighLevelILFunction(
    BNFlowGraph* graph, BNHighLevelILFunction* func) {}
BINARYNINJACOREAPI BNFlowGraphNode** BNGetFlowGraphNodes(BNFlowGraph* graph,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraphNode* BNGetFlowGraphNode(BNFlowGraph* graph,
                                                       size_t i) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraphNode** BNGetFlowGraphNodesInRegion(
    BNFlowGraph* graph, int left, int top, int right, int bottom,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlowGraphNodeList(BNFlowGraphNode** nodes,
                                                size_t count) {}
BINARYNINJACOREAPI size_t BNGetFlowGraphNodeCount(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI bool BNFlowGraphHasNodes(BNFlowGraph* graph) { return {}; }
BINARYNINJACOREAPI size_t BNAddFlowGraphNode(BNFlowGraph* graph,
                                             BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNReplaceFlowGraphNode(BNFlowGraph* graph, size_t i,
                                               BNFlowGraphNode* newNode) {}
BINARYNINJACOREAPI void BNClearFlowGraphNodes(BNFlowGraph* graph) {}
BINARYNINJACOREAPI int BNGetFlowGraphWidth(BNFlowGraph* graph) { return {}; }
BINARYNINJACOREAPI int BNGetFlowGraphHeight(BNFlowGraph* graph) { return {}; }
BINARYNINJACOREAPI void BNFlowGraphSetWidth(BNFlowGraph* graph, int width) {}
BINARYNINJACOREAPI void BNFlowGraphSetHeight(BNFlowGraph* graph, int height) {}
BINARYNINJACOREAPI BNRenderLayer** BNGetFlowGraphRenderLayers(
    BNFlowGraph* graph, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddFlowGraphRenderLayer(BNFlowGraph* graph,
                                                  BNRenderLayer* layer) {}
BINARYNINJACOREAPI void BNRemoveFlowGraphRenderLayer(BNFlowGraph* graph,
                                                     BNRenderLayer* layer) {}
BINARYNINJACOREAPI BNFlowGraphNode* BNCreateFlowGraphNode(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraphNode* BNNewFlowGraphNodeReference(
    BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlowGraphNode(BNFlowGraphNode* node) {}
BINARYNINJACOREAPI BNFlowGraph* BNGetFlowGraphNodeOwner(BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetFlowGraphBasicBlock(
    BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNSetFlowGraphBasicBlock(BNFlowGraphNode* node,
                                                 BNBasicBlock* block) {}
BINARYNINJACOREAPI void BNFlowGraphNodeSetX(BNFlowGraphNode* node, int x) {}
BINARYNINJACOREAPI void BNFlowGraphNodeSetY(BNFlowGraphNode* node, int y) {}
BINARYNINJACOREAPI int BNGetFlowGraphNodeX(BNFlowGraphNode* node) { return {}; }
BINARYNINJACOREAPI int BNGetFlowGraphNodeY(BNFlowGraphNode* node) { return {}; }
BINARYNINJACOREAPI int BNGetFlowGraphNodeWidth(BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI int BNGetFlowGraphNodeHeight(BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNGetFlowGraphNodeLines(
    BNFlowGraphNode* node, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSetFlowGraphNodeLines(BNFlowGraphNode* node,
                                                BNDisassemblyTextLine* lines,
                                                size_t count) {}
BINARYNINJACOREAPI BNFlowGraphEdge* BNGetFlowGraphNodeOutgoingEdges(
    BNFlowGraphNode* node, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraphEdge* BNGetFlowGraphNodeIncomingEdges(
    BNFlowGraphNode* node, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlowGraphNodeEdgeList(BNFlowGraphEdge* edges,
                                                    size_t count) {}
BINARYNINJACOREAPI void BNAddFlowGraphNodeOutgoingEdge(BNFlowGraphNode* node,
                                                       BNBranchType type,
                                                       BNFlowGraphNode* target,
                                                       BNEdgeStyle edgeStyle) {}
BINARYNINJACOREAPI BNHighlightColor
BNGetFlowGraphNodeHighlight(BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNSetFlowGraphNodeHighlight(BNFlowGraphNode* node,
                                                    BNHighlightColor color) {}
BINARYNINJACOREAPI void BNFinishPrepareForLayout(BNFlowGraph* graph) {}
BINARYNINJACOREAPI bool BNFlowGraphUpdateQueryMode(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI bool BNFlowGraphHasUpdates(BNFlowGraph* graph) { return {}; }
BINARYNINJACOREAPI BNFlowGraph* BNUpdateFlowGraph(BNFlowGraph* graph) {
  return {};
}
BINARYNINJACOREAPI void BNSetFlowGraphOption(BNFlowGraph* graph,
                                             BNFlowGraphOption option,
                                             bool value) {}
BINARYNINJACOREAPI bool BNIsFlowGraphOptionSet(BNFlowGraph* graph,
                                               BNFlowGraphOption option) {
  return {};
}
BINARYNINJACOREAPI bool BNIsNodeValidForFlowGraph(BNFlowGraph* graph,
                                                  BNFlowGraphNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNFlowGraphNodeSetVisibilityRegion(
    BNFlowGraphNode* node, int x, int y, int w, int h) {}
BINARYNINJACOREAPI void BNFlowGraphNodeSetOutgoingEdgePoints(
    BNFlowGraphNode* node, size_t edgeNum, BNPoint* points, size_t pointCount) {
}
BINARYNINJACOREAPI BNFlowGraphLayout** BNGetFlowGraphLayouts(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFlowGraphLayoutList(BNFlowGraphLayout** layouts) {
}
BINARYNINJACOREAPI BNFlowGraphLayout* BNRegisterFlowGraphLayout(
    const char* name, BNCustomFlowGraphLayout* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraphLayout* BNGetFlowGraphLayoutByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetFlowGraphLayoutName(BNFlowGraphLayout* layout) {
  return {};
}
BINARYNINJACOREAPI bool BNFlowGraphLayoutLayout(BNFlowGraphLayout* layout,
                                                BNFlowGraph* graph,
                                                BNFlowGraphNode** nodes,
                                                size_t nodeCount) {
  return {};
}
BINARYNINJACOREAPI BNSymbol* BNCreateSymbol(
    BNSymbolType type, const char* shortName, const char* fullName,
    const char* rawName, uint64_t addr, BNSymbolBinding binding,
    const BNNameSpace* nameSpace, uint64_t ordinal) {
  return {};
}
BINARYNINJACOREAPI BNSymbol* BNNewSymbolReference(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI void BNFreeSymbol(BNSymbol* sym) {}
BINARYNINJACOREAPI BNSymbolType BNGetSymbolType(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI BNSymbolBinding BNGetSymbolBinding(BNSymbol* sym) {
  return {};
}
BINARYNINJACOREAPI BNNameSpace BNGetSymbolNameSpace(BNSymbol* sym) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSymbolShortName(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI BNStringRef* BNGetSymbolShortNameRef(BNSymbol* sym) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSymbolFullName(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI BNStringRef* BNGetSymbolFullNameRef(BNSymbol* sym) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSymbolRawName(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI BNStringRef* BNGetSymbolRawNameRef(BNSymbol* sym) {
  return {};
}
BINARYNINJACOREAPI void* BNGetSymbolRawBytes(BNSymbol* sym, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSymbolRawBytes(void* bytes) {}
BINARYNINJACOREAPI uint64_t BNGetSymbolAddress(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetSymbolOrdinal(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI bool BNIsSymbolAutoDefined(BNSymbol* sym) { return {}; }
BINARYNINJACOREAPI BNSymbol* BNGetSymbolByAddress(
    BNBinaryView* view, uint64_t addr, const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol* BNGetSymbolByRawName(
    BNBinaryView* view, const char* name, const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol** BNGetSymbolsByName(BNBinaryView* view,
                                                 const char* name,
                                                 size_t* count,
                                                 const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol** BNGetSymbolsByRawName(
    BNBinaryView* view, const char* name, size_t* count,
    const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol** BNGetSymbols(BNBinaryView* view, size_t* count,
                                           const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol** BNGetSymbolsInRange(
    BNBinaryView* view, uint64_t start, uint64_t len, size_t* count,
    const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol** BNGetSymbolsOfType(BNBinaryView* view,
                                                 BNSymbolType type,
                                                 size_t* count,
                                                 const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI BNSymbol** BNGetSymbolsOfTypeInRange(
    BNBinaryView* view, BNSymbolType type, uint64_t start, uint64_t len,
    size_t* count, const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSymbolList(BNSymbol** syms, size_t count) {}
BINARYNINJACOREAPI BNSymbol** BNGetVisibleSymbols(
    BNBinaryView* view, size_t* count, const BNNameSpace* nameSpace) {
  return {};
}
BINARYNINJACOREAPI void BNDefineAutoSymbol(BNBinaryView* view, BNSymbol* sym) {}
BINARYNINJACOREAPI void BNUndefineAutoSymbol(BNBinaryView* view,
                                             BNSymbol* sym) {}
BINARYNINJACOREAPI void BNDefineUserSymbol(BNBinaryView* view, BNSymbol* sym) {}
BINARYNINJACOREAPI void BNUndefineUserSymbol(BNBinaryView* view,
                                             BNSymbol* sym) {}
BINARYNINJACOREAPI void BNDefineImportedFunction(BNBinaryView* view,
                                                 BNSymbol* importAddressSym,
                                                 BNFunction* func,
                                                 BNType* type) {}
BINARYNINJACOREAPI BNSymbol* BNDefineAutoSymbolAndVariableOrFunction(
    BNBinaryView* view, BNPlatform* platform, BNSymbol* sym,
    BNTypeWithConfidence* type) {
  return {};
}
BINARYNINJACOREAPI void BNBeginBulkModifySymbols(BNBinaryView* view) {}
BINARYNINJACOREAPI void BNEndBulkModifySymbols(BNBinaryView* view) {}
BINARYNINJACOREAPI BNDebugInfo* BNGetDebugInfo(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNApplyDebugInfo(BNBinaryView* view,
                                         BNDebugInfo* newDebugInfo) {}
BINARYNINJACOREAPI void BNSetDebugInfo(BNBinaryView* view,
                                       BNDebugInfo* newDebugInfo) {}
BINARYNINJACOREAPI bool BNIsApplyingDebugInfo(BNBinaryView* view) { return {}; }
BINARYNINJACOREAPI BNSymbol* BNImportedFunctionFromImportAddressSymbol(
    BNSymbol* sym, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNCreateLowLevelILFunction(
    BNArchitecture* arch, BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNNewLowLevelILFunctionReference(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLowLevelILFunction(BNLowLevelILFunction* func) {}
BINARYNINJACOREAPI BNFunction* BNGetLowLevelILOwnerFunction(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNLowLevelILGetCurrentAddress(BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNLowLevelILSetCurrentAddress(
    BNLowLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {}
BINARYNINJACOREAPI void BNLowLevelILSetCurrentSourceBlock(
    BNLowLevelILFunction* func, BNBasicBlock* source) {}
BINARYNINJACOREAPI size_t BNLowLevelILGetInstructionStart(
    BNLowLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI size_t* BNLowLevelILGetInstructionsAt(
    BNLowLevelILFunction* func, BNArchitecture* arch, uint64_t addr,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNLowLevelILGetExitsForInstruction(
    BNLowLevelILFunction* func, size_t instr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNLowLevelILClearIndirectBranches(
    BNLowLevelILFunction* func) {}
BINARYNINJACOREAPI void BNLowLevelILSetIndirectBranches(
    BNLowLevelILFunction* func, BNArchitectureAndAddress* branches,
    size_t count) {}
BINARYNINJACOREAPI size_t BNLowLevelILAddExpr(BNLowLevelILFunction* func,
                                              BNLowLevelILOperation operation,
                                              size_t size, uint32_t flags,
                                              uint64_t a, uint64_t b,
                                              uint64_t c, uint64_t d) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILAddExprWithLocation(
    BNLowLevelILFunction* func, uint64_t addr, uint32_t sourceOperand,
    BNLowLevelILOperation operation, size_t size, uint32_t flags, uint64_t a,
    uint64_t b, uint64_t c, uint64_t d) {
  return {};
}
BINARYNINJACOREAPI void BNLowLevelILSetExprSourceOperand(
    BNLowLevelILFunction* func, size_t expr, uint32_t operand) {}
BINARYNINJACOREAPI size_t BNLowLevelILAddInstruction(BNLowLevelILFunction* func,
                                                     size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILGoto(BNLowLevelILFunction* func,
                                           BNLowLevelILLabel* label) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILGotoWithLocation(
    BNLowLevelILFunction* func, BNLowLevelILLabel* label, uint64_t addr,
    uint32_t sourceOperand) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILIf(BNLowLevelILFunction* func,
                                         uint64_t op, BNLowLevelILLabel* t,
                                         BNLowLevelILLabel* f) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILIfWithLocation(
    BNLowLevelILFunction* func, uint64_t op, BNLowLevelILLabel* t,
    BNLowLevelILLabel* f, uint64_t addr, uint32_t sourceOperand) {
  return {};
}
BINARYNINJACOREAPI void BNLowLevelILInitLabel(BNLowLevelILLabel* label) {}
BINARYNINJACOREAPI void BNLowLevelILMarkLabel(BNLowLevelILFunction* func,
                                              BNLowLevelILLabel* label) {}
BINARYNINJACOREAPI void BNFinalizeLowLevelILFunction(
    BNLowLevelILFunction* func) {}
BINARYNINJACOREAPI void BNGenerateLowLevelILSSAForm(
    BNLowLevelILFunction* func) {}
BINARYNINJACOREAPI bool BNLowLevelILFunctionHasIndirectBranches(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNPrepareToCopyLowLevelILFunction(
    BNLowLevelILFunction* func, BNLowLevelILFunction* src) {}
BINARYNINJACOREAPI void BNPrepareToCopyLowLevelILBasicBlock(
    BNLowLevelILFunction* func, BNBasicBlock* block) {}
BINARYNINJACOREAPI BNLowLevelILLabel* BNGetLabelForLowLevelILSourceInstruction(
    BNLowLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNPrepareToCopyForeignFunction(
    BNLowLevelILFunction* dst, BNLowLevelILFunction* src, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILAddLabelMap(BNLowLevelILFunction* func,
                                                  uint64_t* values,
                                                  BNLowLevelILLabel** labels,
                                                  size_t count) {
  return {};
}
BINARYNINJACOREAPI size_t BNLowLevelILAddOperandList(BNLowLevelILFunction* func,
                                                     uint64_t* operands,
                                                     size_t count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNLowLevelILGetOperandList(
    BNLowLevelILFunction* func, size_t expr, size_t operand, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNLowLevelILFreeOperandList(uint64_t* operands) {}
BINARYNINJACOREAPI uint64_t BNLowLevelILGetOperand(BNLowLevelILFunction* func,
                                                   size_t offset) {
  return {};
}
BINARYNINJACOREAPI size_t BNCacheLowLevelILPossibleValueSet(
    BNLowLevelILFunction* func, BNPossibleValueSet* pvs) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetCachedLowLevelILPossibleValueSet(BNLowLevelILFunction* func, size_t idx) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILInstruction
BNGetLowLevelILByIndex(BNLowLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILIndexForInstruction(BNLowLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILInstructionForExpr(BNLowLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILInstructionCount(BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetLowLevelILExprCount(BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNUpdateLowLevelILOperand(BNLowLevelILFunction* func,
                                                  size_t instr,
                                                  size_t operandIndex,
                                                  uint64_t value) {}
BINARYNINJACOREAPI void BNReplaceLowLevelILExpr(BNLowLevelILFunction* func,
                                                size_t expr, size_t newExpr) {}
BINARYNINJACOREAPI void BNSetLowLevelILExprAttributes(
    BNLowLevelILFunction* func, size_t expr, uint32_t attributes) {}
BINARYNINJACOREAPI void BNAddLowLevelILLabelForAddress(
    BNLowLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {}
BINARYNINJACOREAPI BNLowLevelILLabel* BNGetLowLevelILLabelForAddress(
    BNLowLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI void BNPrepareBlockTranslation(BNLowLevelILFunction* func,
                                                  BNArchitecture* arch,
                                                  uint64_t addr) {}
BINARYNINJACOREAPI bool BNGetLowLevelILExprText(BNLowLevelILFunction* func,
                                                BNArchitecture* arch, size_t i,
                                                BNDisassemblySettings* settings,
                                                BNInstructionTextToken** tokens,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetLowLevelILInstructionText(
    BNLowLevelILFunction* il, BNFunction* func, BNArchitecture* arch, size_t i,
    BNDisassemblySettings* settings, BNInstructionTextToken** tokens,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetLowLevelILTemporaryRegisterCount(BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetLowLevelILTemporaryFlagCount(BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetLowLevelILBasicBlockList(
    BNLowLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetLowLevelILBasicBlockForInstruction(
    BNLowLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetLowLevelILSSAForm(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetLowLevelILNonSSAForm(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILSSAInstructionIndex(BNLowLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetLowLevelILNonSSAInstructionIndex(
    BNLowLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILSSAExprIndex(BNLowLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILNonSSAExprIndex(BNLowLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetLowLevelILSSARegisterDefinition(
    BNLowLevelILFunction* func, uint32_t reg, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetLowLevelILSSAFlagDefinition(
    BNLowLevelILFunction* func, uint32_t reg, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILSSAMemoryDefinition(BNLowLevelILFunction* func, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelILSSARegisterUses(
    BNLowLevelILFunction* func, uint32_t reg, size_t version, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelILSSAFlagUses(
    BNLowLevelILFunction* func, uint32_t reg, size_t version, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelILSSAMemoryUses(
    BNLowLevelILFunction* func, size_t version, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILSSARegisterValue(
    BNLowLevelILFunction* func, uint32_t reg, size_t version) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILSSAFlagValue(
    BNLowLevelILFunction* func, uint32_t flag, size_t version) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue
BNGetLowLevelILExprValue(BNLowLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNGetLowLevelILPossibleExprValues(
    BNLowLevelILFunction* func, size_t expr, BNDataFlowQueryOption* options,
    size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILRegisterValueAtInstruction(
    BNLowLevelILFunction* func, uint32_t reg, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILRegisterValueAfterInstruction(
    BNLowLevelILFunction* func, uint32_t reg, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetLowLevelILPossibleRegisterValuesAtInstruction(
    BNLowLevelILFunction* func, uint32_t reg, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetLowLevelILPossibleRegisterValuesAfterInstruction(
    BNLowLevelILFunction* func, uint32_t reg, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILFlagValueAtInstruction(
    BNLowLevelILFunction* func, uint32_t flag, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILFlagValueAfterInstruction(
    BNLowLevelILFunction* func, uint32_t flag, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetLowLevelILPossibleFlagValuesAtInstruction(BNLowLevelILFunction* func,
                                               uint32_t flag, size_t instr,
                                               BNDataFlowQueryOption* options,
                                               size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetLowLevelILPossibleFlagValuesAfterInstruction(
    BNLowLevelILFunction* func, uint32_t flag, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILStackContentsAtInstruction(
    BNLowLevelILFunction* func, int64_t offset, size_t len, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetLowLevelILStackContentsAfterInstruction(
    BNLowLevelILFunction* func, int64_t offset, size_t len, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetLowLevelILPossibleStackContentsAtInstruction(
    BNLowLevelILFunction* func, int64_t offset, size_t len, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetLowLevelILPossibleStackContentsAfterInstruction(
    BNLowLevelILFunction* func, int64_t offset, size_t len, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetLowLevelRegisters(BNLowLevelILFunction* func,
                                                    size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetLowLevelRegisterStacks(
    BNLowLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetLowLevelFlags(BNLowLevelILFunction* func,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetLowLevelSSARegistersWithoutVersions(
    BNLowLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetLowLevelSSARegisterStacksWithoutVersions(
    BNLowLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetLowLevelSSAFlagsWithoutVersions(
    BNLowLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelRegisterSSAVersions(
    BNLowLevelILFunction* func, const uint32_t var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelRegisterStackSSAVersions(
    BNLowLevelILFunction* func, const uint32_t var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelFlagSSAVersions(
    BNLowLevelILFunction* func, const uint32_t var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelMemoryVersions(
    BNLowLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLLILVariablesList(uint32_t* vars) {}
BINARYNINJACOREAPI void BNFreeLLILVariableVersionList(size_t* versions) {}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetMediumLevelILForLowLevelIL(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetMappedMediumLevelIL(
    BNLowLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILInstructionIndex(BNLowLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILExprIndex(BNLowLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILExprIndexes(
    BNLowLevelILFunction* func, size_t expr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMappedMediumLevelILInstructionIndex(
    BNLowLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMappedMediumLevelILExprIndex(BNLowLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNCreateMediumLevelILFunction(
    BNArchitecture* arch, BNFunction* func, BNLowLevelILFunction* lowLevelIL) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNNewMediumLevelILFunctionReference(
    BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeMediumLevelILFunction(
    BNMediumLevelILFunction* func) {}
BINARYNINJACOREAPI BNFunction* BNGetMediumLevelILOwnerFunction(
    BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNMediumLevelILGetCurrentAddress(BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNMediumLevelILSetCurrentAddress(
    BNMediumLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {}
BINARYNINJACOREAPI size_t BNMediumLevelILGetInstructionStart(
    BNMediumLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILAddExpr(
    BNMediumLevelILFunction* func, BNMediumLevelILOperation operation,
    size_t size, uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILAddExprWithLocation(
    BNMediumLevelILFunction* func, BNMediumLevelILOperation operation,
    uint64_t addr, uint32_t sourceOperand, size_t size, uint64_t a, uint64_t b,
    uint64_t c, uint64_t d, uint64_t e) {
  return {};
}
BINARYNINJACOREAPI size_t
BNMediumLevelILAddInstruction(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILGoto(BNMediumLevelILFunction* func,
                                              BNMediumLevelILLabel* label) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILGotoWithLocation(
    BNMediumLevelILFunction* func, BNMediumLevelILLabel* label, uint64_t addr,
    uint32_t sourceOperand) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILIf(BNMediumLevelILFunction* func,
                                            uint64_t op,
                                            BNMediumLevelILLabel* t,
                                            BNMediumLevelILLabel* f) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILIfWithLocation(
    BNMediumLevelILFunction* func, uint64_t op, BNMediumLevelILLabel* t,
    BNMediumLevelILLabel* f, uint64_t addr, uint32_t sourceOperand) {
  return {};
}
BINARYNINJACOREAPI void BNMediumLevelILInitLabel(BNMediumLevelILLabel* label) {}
BINARYNINJACOREAPI void BNMediumLevelILMarkLabel(BNMediumLevelILFunction* func,
                                                 BNMediumLevelILLabel* label) {}
BINARYNINJACOREAPI void BNFinalizeMediumLevelILFunction(
    BNMediumLevelILFunction* func) {}
BINARYNINJACOREAPI void BNGenerateMediumLevelILSSAForm(
    BNMediumLevelILFunction* func, bool analyzeConditionals, bool handleAliases,
    BNVariable* knownNotAliases, size_t knownNotAliasCount,
    BNVariable* knownAliases, size_t knownAliasCount) {}
BINARYNINJACOREAPI void BNPrepareToCopyMediumLevelILFunction(
    BNMediumLevelILFunction* func, BNMediumLevelILFunction* src) {}
BINARYNINJACOREAPI void BNPrepareToCopyMediumLevelILBasicBlock(
    BNMediumLevelILFunction* func, BNBasicBlock* block) {}
BINARYNINJACOREAPI BNMediumLevelILLabel*
BNGetLabelForMediumLevelILSourceInstruction(BNMediumLevelILFunction* func,
                                            size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNMediumLevelILAddLabelMap(BNMediumLevelILFunction* func, uint64_t* values,
                           BNMediumLevelILLabel** labels, size_t count) {
  return {};
}
BINARYNINJACOREAPI size_t BNMediumLevelILAddOperandList(
    BNMediumLevelILFunction* func, uint64_t* operands, size_t count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNMediumLevelILGetOperandList(
    BNMediumLevelILFunction* func, size_t expr, size_t operand, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNMediumLevelILFreeOperandList(uint64_t* operands) {}
BINARYNINJACOREAPI uint64_t
BNMediumLevelILGetOperand(BNMediumLevelILFunction* func, size_t offset) {
  return {};
}
BINARYNINJACOREAPI size_t BNCacheMediumLevelILPossibleValueSet(
    BNMediumLevelILFunction* func, BNPossibleValueSet* pvs) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNGetCachedMediumLevelILPossibleValueSet(
    BNMediumLevelILFunction* func, size_t idx) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILInstruction
BNGetMediumLevelILByIndex(BNMediumLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILIndexForInstruction(BNMediumLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILInstructionForExpr(
    BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILInstructionCount(BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILExprCount(BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNUpdateMediumLevelILOperand(
    BNMediumLevelILFunction* func, size_t instr, size_t operandIndex,
    uint64_t value) {}
BINARYNINJACOREAPI void BNMarkMediumLevelILInstructionForRemoval(
    BNMediumLevelILFunction* func, size_t instr) {}
BINARYNINJACOREAPI void BNReplaceMediumLevelILInstruction(
    BNMediumLevelILFunction* func, size_t instr, size_t expr) {}
BINARYNINJACOREAPI void BNReplaceMediumLevelILExpr(
    BNMediumLevelILFunction* func, size_t expr, size_t newExpr) {}
BINARYNINJACOREAPI void BNSetMediumLevelILExprAttributes(
    BNMediumLevelILFunction* func, size_t expr, uint32_t attributes) {}
BINARYNINJACOREAPI bool BNGetMediumLevelILExprText(
    BNMediumLevelILFunction* func, BNArchitecture* arch, size_t i,
    BNInstructionTextToken** tokens, size_t* count,
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI bool BNGetMediumLevelILInstructionText(
    BNMediumLevelILFunction* il, BNFunction* func, BNArchitecture* arch,
    size_t i, BNInstructionTextToken** tokens, size_t* count,
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock** BNGetMediumLevelILBasicBlockList(
    BNMediumLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetMediumLevelILBasicBlockForInstruction(
    BNMediumLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetMediumLevelILSSAForm(
    BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction* BNGetMediumLevelILNonSSAForm(
    BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAInstructionIndex(
    BNMediumLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILNonSSAInstructionIndex(
    BNMediumLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILSSAExprIndex(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetMediumLevelILNonSSAExprIndex(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAVarDefinition(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAMemoryDefinition(
    BNMediumLevelILFunction* func, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILSSAVarUses(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t version,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILSSAMemoryUses(
    BNMediumLevelILFunction* func, size_t version, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMediumLevelILSSAVarLive(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t version) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMediumLevelILSSAVarLiveAt(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t version,
    const size_t instr) {
  return {};
}
BINARYNINJACOREAPI bool BNIsMediumLevelILVarLiveAt(
    BNMediumLevelILFunction* func, const BNVariable* var, const size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable* BNGetMediumLevelILVariables(
    BNMediumLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariable* BNGetMediumLevelILAliasedVariables(
    BNMediumLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILVariableSSAVersions(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILVariableDefinitions(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILVariableUses(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILLiveInstructionsForVariable(
    BNMediumLevelILFunction* func, const BNVariable* var, bool includeLastUse,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t BNGetDefaultIndexForMediumLevelILVariableDefinition(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t instrIndex) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetMediumLevelILSSAVarValue(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t version) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue
BNGetMediumLevelILExprValue(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNGetMediumLevelILPossibleSSAVarValues(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t version,
    size_t instr, BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNGetMediumLevelILPossibleExprValues(
    BNMediumLevelILFunction* func, size_t expr, BNDataFlowQueryOption* options,
    size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAVarVersionAtILInstruction(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAVarVersionAfterILInstruction(
    BNMediumLevelILFunction* func, const BNVariable* var, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAMemoryVersionAtILInstruction(
    BNMediumLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILSSAMemoryVersionAfterILInstruction(
    BNMediumLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable
BNGetMediumLevelILVariableForRegisterAtInstruction(
    BNMediumLevelILFunction* func, uint32_t reg, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable
BNGetMediumLevelILVariableForRegisterAfterInstruction(
    BNMediumLevelILFunction* func, uint32_t reg, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable BNGetMediumLevelILVariableForFlagAtInstruction(
    BNMediumLevelILFunction* func, uint32_t flag, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable BNGetMediumLevelILVariableForFlagAfterInstruction(
    BNMediumLevelILFunction* func, uint32_t flag, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable
BNGetMediumLevelILVariableForStackLocationAtInstruction(
    BNMediumLevelILFunction* func, int64_t offset, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNVariable
BNGetMediumLevelILVariableForStackLocationAfterInstruction(
    BNMediumLevelILFunction* func, int64_t offset, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetMediumLevelILRegisterValueAtInstruction(
    BNMediumLevelILFunction* func, uint32_t reg, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue
BNGetMediumLevelILRegisterValueAfterInstruction(BNMediumLevelILFunction* func,
                                                uint32_t reg, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetMediumLevelILPossibleRegisterValuesAtInstruction(
    BNMediumLevelILFunction* func, uint32_t reg, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetMediumLevelILPossibleRegisterValuesAfterInstruction(
    BNMediumLevelILFunction* func, uint32_t reg, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetMediumLevelILFlagValueAtInstruction(
    BNMediumLevelILFunction* func, uint32_t flag, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetMediumLevelILFlagValueAfterInstruction(
    BNMediumLevelILFunction* func, uint32_t flag, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetMediumLevelILPossibleFlagValuesAtInstruction(
    BNMediumLevelILFunction* func, uint32_t flag, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetMediumLevelILPossibleFlagValuesAfterInstruction(
    BNMediumLevelILFunction* func, uint32_t flag, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetMediumLevelILStackContentsAtInstruction(
    BNMediumLevelILFunction* func, int64_t offset, size_t len, size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue
BNGetMediumLevelILStackContentsAfterInstruction(BNMediumLevelILFunction* func,
                                                int64_t offset, size_t len,
                                                size_t instr) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetMediumLevelILPossibleStackContentsAtInstruction(
    BNMediumLevelILFunction* func, int64_t offset, size_t len, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNGetMediumLevelILPossibleStackContentsAfterInstruction(
    BNMediumLevelILFunction* func, int64_t offset, size_t len, size_t instr,
    BNDataFlowQueryOption* options, size_t optionCount) {
  return {};
}
BINARYNINJACOREAPI BNILBranchDependence BNGetMediumLevelILBranchDependence(
    BNMediumLevelILFunction* func, size_t curInstr, size_t branchInstr) {
  return {};
}
BINARYNINJACOREAPI BNILBranchInstructionAndDependence*
BNGetAllMediumLevelILBranchDependence(BNMediumLevelILFunction* func,
                                      size_t instr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeILBranchDependenceList(
    BNILBranchInstructionAndDependence* branches) {}
BINARYNINJACOREAPI BNLowLevelILFunction* BNGetLowLevelILForMediumLevelIL(
    BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILInstructionIndex(BNMediumLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetLowLevelILExprIndex(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetLowLevelILExprIndexes(
    BNMediumLevelILFunction* func, size_t expr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetHighLevelILForMediumLevelIL(
    BNMediumLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILInstructionIndex(BNMediumLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILExprIndex(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILExprIndexes(
    BNMediumLevelILFunction* func, size_t expr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeWithConfidence
BNGetMediumLevelILExprType(BNMediumLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI void BNSetMediumLevelILExprType(
    BNMediumLevelILFunction* func, size_t expr, BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI BNHighLevelILFunction* BNCreateHighLevelILFunction(
    BNArchitecture* arch, BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNNewHighLevelILFunctionReference(
    BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeHighLevelILFunction(BNHighLevelILFunction* func) {
}
BINARYNINJACOREAPI BNFunction* BNGetHighLevelILOwnerFunction(
    BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNHighLevelILGetCurrentAddress(BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNHighLevelILSetCurrentAddress(
    BNHighLevelILFunction* func, BNArchitecture* arch, uint64_t addr) {}
BINARYNINJACOREAPI size_t BNHighLevelILAddExpr(BNHighLevelILFunction* func,
                                               BNHighLevelILOperation operation,
                                               size_t size, uint64_t a,
                                               uint64_t b, uint64_t c,
                                               uint64_t d, uint64_t e) {
  return {};
}
BINARYNINJACOREAPI size_t BNHighLevelILAddExprWithLocation(
    BNHighLevelILFunction* func, BNHighLevelILOperation operation,
    uint64_t addr, uint32_t sourceOperand, size_t size, uint64_t a, uint64_t b,
    uint64_t c, uint64_t d, uint64_t e) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILRootExpr(BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNSetHighLevelILRootExpr(BNHighLevelILFunction* func,
                                                 size_t expr) {}
BINARYNINJACOREAPI void BNFinalizeHighLevelILFunction(
    BNHighLevelILFunction* func) {}
BINARYNINJACOREAPI void BNGenerateHighLevelILSSAForm(
    BNHighLevelILFunction* func, BNVariable* aliases, size_t aliasCount) {}
BINARYNINJACOREAPI size_t BNHighLevelILAddOperandList(
    BNHighLevelILFunction* func, uint64_t* operands, size_t count) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNHighLevelILGetOperandList(
    BNHighLevelILFunction* func, size_t expr, size_t operand, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNHighLevelILFreeOperandList(uint64_t* operands) {}
BINARYNINJACOREAPI uint64_t BNHighLevelILGetOperand(BNHighLevelILFunction* func,
                                                    size_t offset) {
  return {};
}
BINARYNINJACOREAPI size_t BNCacheHighLevelILPossibleValueSet(
    BNHighLevelILFunction* func, BNPossibleValueSet* pvs) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNGetCachedHighLevelILPossibleValueSet(
    BNHighLevelILFunction* func, size_t idx) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILInstruction
BNGetHighLevelILByIndex(BNHighLevelILFunction* func, size_t i, bool asFullAst) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILIndexForInstruction(BNHighLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILInstructionForExpr(BNHighLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILInstructionCount(BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILExprCount(BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNMediumLevelILFunction*
BNGetMediumLevelILForHighLevelILFunction(BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetMediumLevelILExprIndexFromHighLevelIL(
    BNHighLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetMediumLevelILExprIndexesFromHighLevelIL(
    BNHighLevelILFunction* func, size_t expr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNUpdateHighLevelILOperand(BNHighLevelILFunction* func,
                                                   size_t instr,
                                                   size_t operandIndex,
                                                   uint64_t value) {}
BINARYNINJACOREAPI void BNReplaceHighLevelILExpr(BNHighLevelILFunction* func,
                                                 size_t expr, size_t newExpr) {}
BINARYNINJACOREAPI void BNSetHighLevelILExprAttributes(
    BNHighLevelILFunction* func, size_t expr, uint32_t attributes) {}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNGetHighLevelILExprText(
    BNHighLevelILFunction* func, size_t expr, bool asFullAst, size_t* count,
    BNDisassemblySettings* settings) {
  return {};
}
BINARYNINJACOREAPI BNTypeWithConfidence
BNGetHighLevelILExprType(BNHighLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI void BNSetHighLevelILExprType(BNHighLevelILFunction* func,
                                                 size_t expr,
                                                 BNTypeWithConfidence* type) {}
BINARYNINJACOREAPI BNBasicBlock** BNGetHighLevelILBasicBlockList(
    BNHighLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBasicBlock* BNGetHighLevelILBasicBlockForInstruction(
    BNHighLevelILFunction* func, size_t i) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetHighLevelILSSAForm(
    BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetHighLevelILNonSSAForm(
    BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILSSAInstructionIndex(BNHighLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetHighLevelILNonSSAInstructionIndex(
    BNHighLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILSSAExprIndex(BNHighLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILNonSSAExprIndex(BNHighLevelILFunction* func, size_t expr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetHighLevelILSSAVarDefinition(
    BNHighLevelILFunction* func, const BNVariable* var, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetHighLevelILSSAMemoryDefinition(
    BNHighLevelILFunction* func, size_t version) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILSSAVarUses(
    BNHighLevelILFunction* func, const BNVariable* var, size_t version,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILSSAMemoryUses(
    BNHighLevelILFunction* func, size_t version, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNIsHighLevelILSSAVarLive(BNHighLevelILFunction* func,
                                                  const BNVariable* var,
                                                  size_t version) {
  return {};
}
BINARYNINJACOREAPI bool BNIsHighLevelILSSAVarLiveAt(BNHighLevelILFunction* func,
                                                    const BNVariable* var,
                                                    const size_t version,
                                                    const size_t instr) {
  return {};
}
BINARYNINJACOREAPI bool BNIsHighLevelILVarLiveAt(BNHighLevelILFunction* func,
                                                 const BNVariable* var,
                                                 const size_t instr) {
  return {};
}
BINARYNINJACOREAPI bool BNHighLevelILHasSideEffects(BNHighLevelILFunction* func,
                                                    size_t exprIndex) {
  return {};
}
BINARYNINJACOREAPI BNScopeType
BNGetHighLevelILExprScopeType(BNHighLevelILFunction* func, size_t exprIndex) {
  return {};
}
BINARYNINJACOREAPI BNVariable* BNGetHighLevelILVariables(
    BNHighLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariable* BNGetHighLevelILAliasedVariables(
    BNHighLevelILFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILVariableSSAVersions(
    BNHighLevelILFunction* func, const BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILVariableDefinitions(
    BNHighLevelILFunction* func, const BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILVariableUses(
    BNHighLevelILFunction* func, const BNVariable* var, size_t* count) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetHighLevelILSSAVarVersionAtILInstruction(
    BNHighLevelILFunction* func, const BNVariable* var, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetHighLevelILSSAMemoryVersionAtILInstruction(
    BNHighLevelILFunction* func, size_t instr) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetHighLevelILExprIndexForLabel(BNHighLevelILFunction* func, uint64_t label) {
  return {};
}
BINARYNINJACOREAPI size_t* BNGetHighLevelILUsesForLabel(
    BNHighLevelILFunction* func, uint64_t label, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNHighLevelILExprLessThan(
    BNHighLevelILFunction* leftFunc, size_t leftExpr,
    BNHighLevelILFunction* rightFunc, size_t rightExpr) {
  return {};
}
BINARYNINJACOREAPI bool BNHighLevelILExprEqual(BNHighLevelILFunction* leftFunc,
                                               size_t leftExpr,
                                               BNHighLevelILFunction* rightFunc,
                                               size_t rightExpr) {
  return {};
}
BINARYNINJACOREAPI void BNSetHighLevelILDerivedStringReferenceForExpr(
    BNHighLevelILFunction* func, size_t expr, BNDerivedString* str) {}
BINARYNINJACOREAPI void BNRemoveHighLevelILDerivedStringReferenceForExpr(
    BNHighLevelILFunction* func, size_t expr) {}
BINARYNINJACOREAPI bool BNGetHighLevelILDerivedStringReferenceForExpr(
    BNHighLevelILFunction* func, size_t expr, BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary* BNNewTypeLibrary(BNArchitecture* arch,
                                                   const char* name) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary* BNNewTypeLibraryReference(
    BNTypeLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary* BNDuplicateTypeLibrary(BNTypeLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary* BNLoadTypeLibraryFromFile(const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeLibraryDecompressToFile(BNTypeLibrary* lib,
                                                      const char* output) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeLibrary(BNTypeLibrary* lib) {}
BINARYNINJACOREAPI BNTypeLibrary* BNLookupTypeLibraryByName(
    BNArchitecture* arch, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary* BNLookupTypeLibraryByGuid(
    BNArchitecture* arch, const char* guid) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary** BNGetArchitectureTypeLibraries(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeLibraryList(BNTypeLibrary** lib,
                                              size_t count) {}
BINARYNINJACOREAPI bool BNFinalizeTypeLibrary(BNTypeLibrary* lib) { return {}; }
BINARYNINJACOREAPI void BNRegisterTypeLibrary(BNTypeLibrary* lib) {}
BINARYNINJACOREAPI BNArchitecture* BNGetTypeLibraryArchitecture(
    BNTypeLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeLibraryName(BNTypeLibrary* lib,
                                             const char* name) {}
BINARYNINJACOREAPI char* BNGetTypeLibraryName(BNTypeLibrary* lib) { return {}; }
BINARYNINJACOREAPI void BNAddTypeLibraryAlternateName(BNTypeLibrary* lib,
                                                      const char* name) {}
BINARYNINJACOREAPI void BNRemoveTypeLibraryAlternateName(BNTypeLibrary* lib,
                                                         const char* name) {}
BINARYNINJACOREAPI char** BNGetTypeLibraryAlternateNames(BNTypeLibrary* lib,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeLibraryDependencyName(BNTypeLibrary* lib,
                                                       const char* name) {}
BINARYNINJACOREAPI char* BNGetTypeLibraryDependencyName(BNTypeLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeLibraryGuid(BNTypeLibrary* lib,
                                             const char* name) {}
BINARYNINJACOREAPI char* BNGetTypeLibraryGuid(BNTypeLibrary* lib) { return {}; }
BINARYNINJACOREAPI void BNClearTypeLibraryPlatforms(BNTypeLibrary* lib) {}
BINARYNINJACOREAPI void BNAddTypeLibraryPlatform(BNTypeLibrary* lib,
                                                 BNPlatform* platform) {}
BINARYNINJACOREAPI char** BNGetTypeLibraryPlatforms(BNTypeLibrary* lib,
                                                    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNTypeLibraryStoreMetadata(BNTypeLibrary* lib,
                                                   const char* key,
                                                   BNMetadata* value) {}
BINARYNINJACOREAPI BNMetadata* BNTypeLibraryQueryMetadata(BNTypeLibrary* lib,
                                                          const char* key) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNTypeLibraryGetMetadata(BNTypeLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI void BNTypeLibraryRemoveMetadata(BNTypeLibrary* lib,
                                                    const char* key) {}
BINARYNINJACOREAPI BNTypeContainer* BNGetTypeLibraryTypeContainer(
    BNTypeLibrary* lib) {
  return {};
}
BINARYNINJACOREAPI void BNAddTypeLibraryNamedObject(BNTypeLibrary* lib,
                                                    BNQualifiedName* name,
                                                    BNType* type) {}
BINARYNINJACOREAPI void BNRemoveTypeLibraryNamedObject(BNTypeLibrary* lib,
                                                       BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNAddTypeLibraryNamedType(BNTypeLibrary* lib,
                                                  BNQualifiedName* name,
                                                  BNType* type) {}
BINARYNINJACOREAPI void BNRemoveTypeLibraryNamedType(BNTypeLibrary* lib,
                                                     BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNAddTypeLibraryNamedTypeSource(BNTypeLibrary* lib,
                                                        BNQualifiedName* name,
                                                        const char* source) {}
BINARYNINJACOREAPI BNType* BNGetTypeLibraryNamedObject(BNTypeLibrary* lib,
                                                       BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetTypeLibraryNamedType(BNTypeLibrary* lib,
                                                     BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeLibraryNamedTypeSource(
    BNTypeLibrary* lib, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType* BNGetTypeLibraryNamedObjects(
    BNTypeLibrary* lib, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType* BNGetTypeLibraryNamedTypes(
    BNTypeLibrary* lib, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNWriteTypeLibraryToFile(BNTypeLibrary* lib,
                                                 const char* path) {
  return {};
}
BINARYNINJACOREAPI void BNAddBinaryViewTypeLibrary(BNBinaryView* view,
                                                   BNTypeLibrary* lib) {}
BINARYNINJACOREAPI BNTypeLibrary* BNGetBinaryViewTypeLibrary(BNBinaryView* view,
                                                             const char* name) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary** BNGetBinaryViewTypeLibraries(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType* BNBinaryViewImportTypeLibraryType(
    BNBinaryView* view, BNTypeLibrary** lib, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNType* BNBinaryViewImportTypeLibraryObject(
    BNBinaryView* view, BNTypeLibrary** lib, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNType* BNBinaryViewImportTypeLibraryTypeByGuid(
    BNBinaryView* view, const char* guid) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName
BNBinaryViewGetTypeNameByGuid(BNBinaryView* view, const char* guid) {
  return {};
}
BINARYNINJACOREAPI void BNBinaryViewExportTypeToTypeLibrary(
    BNBinaryView* view, BNTypeLibrary* lib, BNQualifiedName* name,
    BNType* type) {}
BINARYNINJACOREAPI void BNBinaryViewExportObjectToTypeLibrary(
    BNBinaryView* view, BNTypeLibrary* lib, BNQualifiedName* name,
    BNType* type) {}
BINARYNINJACOREAPI void BNBinaryViewSetManualDependencies(
    BNBinaryView* view, BNQualifiedName* viewTypeNames,
    BNQualifiedName* libTypeNames, char** libNames, size_t count) {}
BINARYNINJACOREAPI void BNBinaryViewRecordImportedObjectLibrary(
    BNBinaryView* view, BNPlatform* tgtPlatform, uint64_t tgtAddr,
    BNTypeLibrary* lib, BNQualifiedName* name) {}
BINARYNINJACOREAPI bool BNBinaryViewLookupImportedObjectLibrary(
    BNBinaryView* view, BNPlatform* tgtPlatform, uint64_t tgtAddr,
    BNTypeLibrary** lib, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewLookupImportedTypeLibrary(
    BNBinaryView* view, const BNQualifiedName* typeName, BNTypeLibrary** lib,
    BNQualifiedName* resultName) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunctionType*
BNRegisterLanguageRepresentationFunctionType(
    const char* name, BNCustomLanguageRepresentationFunctionType* type) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunctionType*
BNGetLanguageRepresentationFunctionTypeByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunctionType**
BNGetLanguageRepresentationFunctionTypeList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLanguageRepresentationFunctionTypeList(
    BNLanguageRepresentationFunctionType** types) {}
BINARYNINJACOREAPI char* BNGetLanguageRepresentationFunctionTypeName(
    BNLanguageRepresentationFunctionType* type) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunction*
BNCreateLanguageRepresentationFunction(
    BNLanguageRepresentationFunctionType* type, BNArchitecture* arch,
    BNFunction* func, BNHighLevelILFunction* highLevelIL) {
  return {};
}
BINARYNINJACOREAPI bool BNIsLanguageRepresentationFunctionTypeValid(
    BNLanguageRepresentationFunctionType* type, BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNTypePrinter*
BNGetLanguageRepresentationFunctionTypePrinter(
    BNLanguageRepresentationFunctionType* type) {
  return {};
}
BINARYNINJACOREAPI BNTypeParser* BNGetLanguageRepresentationFunctionTypeParser(
    BNLanguageRepresentationFunctionType* type) {
  return {};
}
BINARYNINJACOREAPI BNLineFormatter*
BNGetLanguageRepresentationFunctionTypeLineFormatter(
    BNLanguageRepresentationFunctionType* type) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine*
BNGetLanguageRepresentationFunctionTypeFunctionTypeTokens(
    BNLanguageRepresentationFunctionType* type, BNFunction* func,
    BNDisassemblySettings* settings, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunction*
BNCreateCustomLanguageRepresentationFunction(
    BNLanguageRepresentationFunctionType* type, BNArchitecture* arch,
    BNFunction* func, BNHighLevelILFunction* highLevelIL,
    BNCustomLanguageRepresentationFunction* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNLanguageRepresentationFunction*
BNNewLanguageRepresentationFunctionReference(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLanguageRepresentationFunction(
    BNLanguageRepresentationFunction* func) {}
BINARYNINJACOREAPI BNLanguageRepresentationFunctionType*
BNGetLanguageRepresentationType(BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNGetLanguageRepresentationArchitecture(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNGetLanguageRepresentationOwnerFunction(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILFunction* BNGetLanguageRepresentationILFunction(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine*
BNGetLanguageRepresentationFunctionExprText(
    BNLanguageRepresentationFunction* func, BNHighLevelILFunction* il,
    size_t exprIndex, BNDisassemblySettings* settings, bool asFullAst,
    BNOperatorPrecedence precedence, bool statement, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine*
BNGetLanguageRepresentationFunctionLinearLines(
    BNLanguageRepresentationFunction* func, BNHighLevelILFunction* il,
    size_t exprIndex, BNDisassemblySettings* settings, bool asFullAst,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine*
BNGetLanguageRepresentationFunctionBlockLines(
    BNLanguageRepresentationFunction* func, BNBasicBlock* block,
    BNDisassemblySettings* settings, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNHighlightColor
BNGetLanguageRepresentationFunctionHighlight(
    BNLanguageRepresentationFunction* func, BNBasicBlock* block) {
  return {};
}
BINARYNINJACOREAPI char* BNGetLanguageRepresentationFunctionCommentStartString(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI char* BNGetLanguageRepresentationFunctionCommentEndString(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI char*
BNGetLanguageRepresentationFunctionAnnotationStartString(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI char* BNGetLanguageRepresentationFunctionAnnotationEndString(
    BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNFieldResolutionInfo* BNNewFieldResolutionInfoReference(
    BNFieldResolutionInfo* info) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFieldResolutionInfo(BNFieldResolutionInfo* info) {
}
BINARYNINJACOREAPI bool BNTypesEqual(BNType* a, BNType* b) { return {}; }
BINARYNINJACOREAPI bool BNTypesNotEqual(BNType* a, BNType* b) { return {}; }
BINARYNINJACOREAPI BNType* BNCreateVoidType(void) { return {}; }
BINARYNINJACOREAPI BNType* BNCreateBoolType(void) { return {}; }
BINARYNINJACOREAPI BNType* BNCreateIntegerType(size_t width,
                                               BNBoolWithConfidence* sign,
                                               const char* altName) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateFloatType(size_t width,
                                             const char* altName) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateWideCharType(size_t width,
                                                const char* altName) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateStructureType(BNStructure* s) { return {}; }
BINARYNINJACOREAPI BNType* BNCreateEnumerationType(
    BNArchitecture* arch, BNEnumeration* e, size_t width,
    BNBoolWithConfidence* isSigned) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateEnumerationTypeOfWidth(
    BNEnumeration* e, size_t width, BNBoolWithConfidence* isSigned) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreatePointerType(
    BNArchitecture* arch, const BNTypeWithConfidence* const type,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl,
    BNReferenceType refType) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreatePointerTypeOfWidth(
    size_t width, const BNTypeWithConfidence* const type,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl,
    BNReferenceType refType) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateFragmentType(
    size_t width, const BNTypeWithConfidence* const type, uint64_t offset,
    BNEndianness endianness) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateFragmentTypeBits(
    size_t width, const BNTypeWithConfidence* const type,
    uint64_t originalFragmentOffsetBytes, size_t originalFragmentWidthBytes,
    BNEndianness endianness, size_t fragmentStartBit, size_t fragmentWidthBits,
    size_t fragmentTruncatedStartBits, size_t wrapBit) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateArrayType(
    const BNTypeWithConfidence* const type, uint64_t elem) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateFunctionType(
    BNReturnValue* returnValue,
    BNCallingConventionWithConfidence* callingConvention,
    BNFunctionParameter* params, size_t paramCount,
    BNBoolWithConfidence* varArg, BNBoolWithConfidence* canReturn,
    BNOffsetWithConfidence* stackAdjust, uint32_t* regStackAdjustRegs,
    BNOffsetWithConfidence* regStackAdjustValues, size_t regStackAdjustCount,
    BNNameType ft, BNBoolWithConfidence* pure) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateVarArgsType() { return {}; }
BINARYNINJACOREAPI BNType* BNCreateValueType(const char* value) { return {}; }
BINARYNINJACOREAPI char* BNGetNameTypeString(BNNameType classFunctionType) {
  return {};
}
BINARYNINJACOREAPI BNType* BNNewTypeReference(BNType* type) { return {}; }
BINARYNINJACOREAPI BNType* BNDuplicateType(BNType* type) { return {}; }
BINARYNINJACOREAPI char* BNGetTypeAndName(BNType* type, BNQualifiedName* name,
                                          BNTokenEscapingType escaping) {
  return {};
}
BINARYNINJACOREAPI void BNFreeType(BNType* type) {}
BINARYNINJACOREAPI void BNFreeTypeList(BNType** types, size_t count) {}
BINARYNINJACOREAPI BNType* BNTypeSetIgnored(BNType* type, bool ignored) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateTypeBuilderFromType(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateVoidTypeBuilder(void) { return {}; }
BINARYNINJACOREAPI BNTypeBuilder* BNCreateBoolTypeBuilder(void) { return {}; }
BINARYNINJACOREAPI BNTypeBuilder* BNCreateIntegerTypeBuilder(
    size_t width, BNBoolWithConfidence* sign, const char* altName) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateFloatTypeBuilder(
    size_t width, const char* altName) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateWideCharTypeBuilder(
    size_t width, const char* altName) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateStructureTypeBuilder(BNStructure* s) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateStructureTypeBuilderWithBuilder(
    BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateEnumerationTypeBuilder(
    BNArchitecture* arch, BNEnumeration* e, size_t width,
    BNBoolWithConfidence* isSigned) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateEnumerationTypeBuilderWithBuilder(
    BNArchitecture* arch, BNEnumerationBuilder* e, size_t width,
    BNBoolWithConfidence* isSigned) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreatePointerTypeBuilder(
    BNArchitecture* arch, const BNTypeWithConfidence* const type,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl,
    BNReferenceType refType) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreatePointerTypeBuilderOfWidth(
    size_t width, const BNTypeWithConfidence* const type,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl,
    BNReferenceType refType) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateFragmentTypeBuilder(
    size_t width, const BNTypeWithConfidence* const type, uint64_t offset,
    BNEndianness endianness) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateFragmentTypeBuilderBits(
    size_t width, const BNTypeWithConfidence* const type,
    uint64_t originalFragmentOffsetBytes, size_t originalFragmentWidthBytes,
    BNEndianness endianness, size_t fragmentStartBit, size_t fragmentWidthBits,
    size_t fragmentTruncatedStartBits, size_t wrapBit) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateArrayTypeBuilder(
    const BNTypeWithConfidence* const type, uint64_t elem) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateFunctionTypeBuilder(
    BNReturnValue* returnValue,
    BNCallingConventionWithConfidence* callingConvention,
    BNFunctionParameter* params, size_t paramCount,
    BNBoolWithConfidence* varArg, BNBoolWithConfidence* canReturn,
    BNOffsetWithConfidence* stackAdjust, uint32_t* regStackAdjustRegs,
    BNOffsetWithConfidence* regStackAdjustValues, size_t regStackAdjustCount,
    BNNameType ft, BNBoolWithConfidence* pure) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateVarArgsTypeBuilder() { return {}; }
BINARYNINJACOREAPI BNTypeBuilder* BNCreateValueTypeBuilder(const char* value) {
  return {};
}
BINARYNINJACOREAPI BNType* BNFinalizeTypeBuilder(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNDuplicateTypeBuilder(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderTypeAndName(BNTypeBuilder* type,
                                                     BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeBuilder(BNTypeBuilder* type) {}
BINARYNINJACOREAPI BNQualifiedName BNTypeGetTypeName(BNType* nt) { return {}; }
BINARYNINJACOREAPI BNTypeClass BNGetTypeClass(BNType* type) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetTypeWidth(BNType* type) { return {}; }
BINARYNINJACOREAPI size_t BNGetTypeAlignment(BNType* type) { return {}; }
BINARYNINJACOREAPI BNIntegerDisplayType
BNGetIntegerTypeDisplayType(BNType* type) {
  return {};
}
BINARYNINJACOREAPI void BNSetIntegerTypeDisplayType(
    BNTypeBuilder* type, BNIntegerDisplayType displayType) {}
BINARYNINJACOREAPI BNBoolWithConfidence BNIsTypeSigned(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence BNIsTypeConst(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence BNIsTypeVolatile(BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNIsTypeFloatingPoint(BNType* type) { return {}; }
BINARYNINJACOREAPI BNTypeWithConfidence BNGetChildType(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNReturnValue BNGetTypeReturnValue(BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNIsTypeReturnValueDefaultLocation(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNValueLocationWithConfidence
BNGetTypeReturnValueLocation(BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNParseValueLocation(const char* str,
                                             BNArchitecture* arch,
                                             BNValueLocation* location,
                                             char** error) {
  return {};
}
BINARYNINJACOREAPI char* BNValueLocationToString(BNValueLocation* location,
                                                 BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI char* BNValueLocationComponentToString(
    BNValueLocationComponent* component, BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNFreeValueLocation(BNValueLocation* location) {}
BINARYNINJACOREAPI BNCallingConventionWithConfidence
BNGetTypeCallingConvention(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNCallingConventionName
BNGetTypeCallingConventionName(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNFunctionParameter* BNGetTypeParameters(BNType* type,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeParameterList(BNFunctionParameter* types,
                                                size_t count) {}
BINARYNINJACOREAPI BNBoolWithConfidence
BNTypeHasVariableArguments(BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeHasTemplateArguments(BNType* type) { return {}; }
BINARYNINJACOREAPI BNBoolWithConfidence BNFunctionTypeCanReturn(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence BNIsTypePure(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNGetTypeStructure(BNType* type) { return {}; }
BINARYNINJACOREAPI BNEnumeration* BNGetTypeEnumeration(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReference* BNGetTypeNamedTypeReference(
    BNType* type) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetTypeElementCount(BNType* type) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetTypeOffset(BNType* type) { return {}; }
BINARYNINJACOREAPI uint64_t BNGetTypeFragmentOriginalOffsetBytes(BNType* type) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetTypeFragmentOriginalWidthBytes(BNType* type) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetTypeFragmentStartBit(BNType* type) { return {}; }
BINARYNINJACOREAPI size_t BNGetTypeFragmentWidthBits(BNType* type) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetTypeFragmentTruncatedStartBits(BNType* type) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetTypeFragmentWrapBit(BNType* type) { return {}; }
BINARYNINJACOREAPI BNEndianness BNGetTypeFragmentEndianness(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNOffsetWithConfidence
BNGetTypeStackAdjustment(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName BNTypeGetStructureName(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReference* BNGetRegisteredTypeName(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNReferenceType BNTypeGetReferenceType(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNPointerBaseType BNTypeGetPointerBaseType(BNType* type) {
  return {};
}
BINARYNINJACOREAPI int64_t BNTypeGetPointerBaseOffset(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNNameType BNTypeGetNameType(BNType* type) { return {}; }
BINARYNINJACOREAPI char* BNGetTypeAlternateName(BNType* type) { return {}; }
BINARYNINJACOREAPI uint32_t BNTypeGetSystemCallNumber(BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeIsSystemCall(BNType* type) { return {}; }
BINARYNINJACOREAPI BNPointerSuffix* BNGetTypePointerSuffix(BNType* type,
                                                           size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypePointerSuffixString(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypePointerSuffixTokens(
    BNType* type, uint8_t baseConfidence, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePointerSuffixList(BNPointerSuffix* suffix,
                                                size_t count) {}
BINARYNINJACOREAPI bool BNTypeShouldDisplayReturnType(BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNTypeAttribute* BNGetTypeAttributes(BNType* type,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeAttributeByName(BNType* type,
                                                  const char* name) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeAttributeList(BNTypeAttribute* attr,
                                                size_t count) {}
BINARYNINJACOREAPI BNType* BNDerefNamedTypeReference(BNBinaryView* view,
                                                     BNType* type) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeString(BNType* type, BNPlatform* platform,
                                         BNTokenEscapingType escaping) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeStringBeforeName(
    BNType* type, BNPlatform* platform, BNTokenEscapingType escaping) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeStringAfterName(
    BNType* type, BNPlatform* platform, BNTokenEscapingType escaping) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeTokens(
    BNType* type, BNPlatform* platform, uint8_t baseConfidence,
    BNTokenEscapingType escaping, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeTokensBeforeName(
    BNType* type, BNPlatform* platform, uint8_t baseConfidence,
    BNTokenEscapingType escaping, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeTokensAfterName(
    BNType* type, BNPlatform* platform, uint8_t baseConfidence,
    BNTokenEscapingType escaping, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType* BNTypeWithReplacedStructure(BNType* type,
                                                       BNStructure* from,
                                                       BNStructure* to) {
  return {};
}
BINARYNINJACOREAPI BNType* BNTypeWithReplacedEnumeration(BNType* type,
                                                         BNEnumeration* from,
                                                         BNEnumeration* to) {
  return {};
}
BINARYNINJACOREAPI BNType* BNTypeWithReplacedNamedTypeReference(
    BNType* type, BNNamedTypeReference* from, BNNamedTypeReference* to) {
  return {};
}
BINARYNINJACOREAPI bool BNAddTypeMemberTokens(
    BNType* type, BNBinaryView* data, BNInstructionTextToken** tokens,
    size_t* tokenCount, int64_t offset, char*** nameList, size_t* nameCount,
    size_t size, bool indirect, BNFieldResolutionInfo* info) {
  return {};
}
BINARYNINJACOREAPI BNTypeDefinitionLine* BNGetTypeLines(
    BNType* type, BNTypeContainer* types, const char* name, int paddingCols,
    bool collapsed, BNTokenEscapingType escaping, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeDefinitionLineList(BNTypeDefinitionLine* list,
                                                     size_t count) {}
BINARYNINJACOREAPI bool BNEnumerateTypesForAccess(
    BNType* type, BNBinaryView* data, uint64_t offset, size_t size,
    uint8_t baseConfidence,
    void (*terminal)(void*, BNTypeWithConfidence*, BNFieldResolutionInfo*),
    void* ctxt) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName BNTypeBuilderGetTypeName(BNTypeBuilder* nt) {
  return {};
}
BINARYNINJACOREAPI void BNTypeBuilderSetTypeName(BNTypeBuilder* type,
                                                 BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNTypeBuilderSetAlternateName(BNTypeBuilder* type,
                                                      const char* name) {}
BINARYNINJACOREAPI BNTypeClass BNGetTypeBuilderClass(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI void BNTypeBuilderSetSystemCallNumber(BNTypeBuilder* type,
                                                         bool v, uint32_t n) {}
BINARYNINJACOREAPI uint64_t BNGetTypeBuilderWidth(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetTypeBuilderAlignment(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNIsTypeBuilderSigned(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNIsTypeBuilderConst(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNIsTypeBuilderVolatile(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI bool BNIsTypeBuilderFloatingPoint(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNTypeWithConfidence
BNGetTypeBuilderChildType(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNReturnValue
BNGetTypeBuilderReturnValue(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI bool BNIsTypeBuilderReturnValueDefaultLocation(
    BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNValueLocationWithConfidence
BNGetTypeBuilderReturnValueLocation(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNCallingConventionWithConfidence
BNGetTypeBuilderCallingConvention(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNCallingConventionName
BNGetTypeBuilderCallingConventionName(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNFunctionParameter* BNGetTypeBuilderParameters(
    BNTypeBuilder* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNTypeBuilderHasVariableArguments(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNFunctionTypeBuilderCanReturn(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNBoolWithConfidence
BNIsTypeBuilderPure(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNGetTypeBuilderStructure(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNEnumeration* BNGetTypeBuilderEnumeration(
    BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReference* BNGetTypeBuilderNamedTypeReference(
    BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeBuilderNamedTypeReference(
    BNTypeBuilder* type, BNNamedTypeReference* ntr) {}
BINARYNINJACOREAPI uint64_t BNGetTypeBuilderElementCount(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetTypeBuilderOffset(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetTypeBuilderFragmentOriginalOffsetBytes(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetTypeBuilderFragmentOriginalWidthBytes(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetTypeBuilderFragmentStartBit(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetTypeBuilderFragmentWidthBits(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI size_t
BNGetTypeBuilderFragmentTruncatedStartBits(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetTypeBuilderFragmentWrapBit(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNEndianness
BNGetTypeBuilderFragmentEndianness(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeBuilderOffset(BNTypeBuilder* type,
                                               uint64_t offset) {}
BINARYNINJACOREAPI void BNSetTypeBuilderPointerBase(BNTypeBuilder* type,
                                                    BNPointerBaseType baseType,
                                                    int64_t baseOffset) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentOriginalOffsetBytes(
    BNTypeBuilder* type, uint64_t offset) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentOriginalWidthBytes(
    BNTypeBuilder* type, size_t size) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentStartBit(BNTypeBuilder* type,
                                                         size_t startBit) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentWidthBits(BNTypeBuilder* type,
                                                          size_t widthBits) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentTruncatedStartBits(
    BNTypeBuilder* type, size_t truncatedBits) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentWrapBit(BNTypeBuilder* type,
                                                        size_t wrapBit) {}
BINARYNINJACOREAPI void BNSetTypeBuilderFragmentEndianness(
    BNTypeBuilder* type, BNEndianness endianness) {}
BINARYNINJACOREAPI void BNSetFunctionTypeBuilderCanReturn(
    BNTypeBuilder* type, BNBoolWithConfidence* canReturn) {}
BINARYNINJACOREAPI void BNSetTypeBuilderPure(BNTypeBuilder* type,
                                             BNBoolWithConfidence* pure) {}
BINARYNINJACOREAPI void BNSetFunctionTypeBuilderParameters(
    BNTypeBuilder* type, BNFunctionParameter* params, size_t paramCount) {}
BINARYNINJACOREAPI void BNTypeBuilderSetWidth(BNTypeBuilder* type,
                                              size_t width) {}
BINARYNINJACOREAPI void BNTypeBuilderSetAlignment(BNTypeBuilder* type,
                                                  size_t alignment) {}
BINARYNINJACOREAPI void BNTypeBuilderSetConst(BNTypeBuilder* type,
                                              BNBoolWithConfidence* cnst) {}
BINARYNINJACOREAPI void BNTypeBuilderSetVolatile(BNTypeBuilder* type,
                                                 BNBoolWithConfidence* vltl) {}
BINARYNINJACOREAPI void BNTypeBuilderSetSigned(BNTypeBuilder* type,
                                               BNBoolWithConfidence* sign) {}
BINARYNINJACOREAPI void BNTypeBuilderSetChildType(BNTypeBuilder* type,
                                                  BNTypeWithConfidence* child) {
}
BINARYNINJACOREAPI void BNTypeBuilderSetReturnValue(BNTypeBuilder* type,
                                                    BNReturnValue* rv) {}
BINARYNINJACOREAPI void BNTypeBuilderSetIsReturnValueDefaultLocation(
    BNTypeBuilder* type, bool defaultLocation) {}
BINARYNINJACOREAPI void BNTypeBuilderSetReturnValueLocation(
    BNTypeBuilder* type, BNValueLocationWithConfidence* location) {}
BINARYNINJACOREAPI void BNTypeBuilderSetCallingConvention(
    BNTypeBuilder* type, BNCallingConventionWithConfidence* cc) {}
BINARYNINJACOREAPI void BNTypeBuilderSetCallingConventionName(
    BNTypeBuilder* type, BNCallingConventionName cc) {}
BINARYNINJACOREAPI BNOffsetWithConfidence
BNGetTypeBuilderStackAdjustment(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName
BNTypeBuilderGetStructureName(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNReferenceType
BNTypeBuilderGetReferenceType(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNPointerBaseType
BNTypeBuilderGetPointerBaseType(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI int64_t
BNTypeBuilderGetPointerBaseOffset(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderAlternateName(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeBuilderIsSystemCall(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNTypeBuilderGetSystemCallNumber(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI void BNTypeBuilderSetStackAdjustment(
    BNTypeBuilder* type, BNOffsetWithConfidence* adjust) {}
BINARYNINJACOREAPI BNPointerSuffix* BNGetTypeBuilderPointerSuffix(
    BNTypeBuilder* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderPointerSuffixString(
    BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeBuilderPointerSuffixTokens(
    BNTypeBuilder* type, uint8_t baseConfidence, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddTypeBuilderPointerSuffix(BNTypeBuilder* type,
                                                      BNPointerSuffix ps) {}
BINARYNINJACOREAPI void BNSetTypeBuilderPointerSuffix(BNTypeBuilder* type,
                                                      BNPointerSuffix* suffix,
                                                      size_t count) {}
BINARYNINJACOREAPI BNNameType BNGetTypeBuilderNameType(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeBuilderHasTemplateArguments(BNTypeBuilder* type) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeBuilderNameType(BNTypeBuilder* type,
                                                 BNNameType nameType) {}
BINARYNINJACOREAPI void BNSetTypeBuilderHasTemplateArguments(
    BNTypeBuilder* type, bool hasTemplateArguments) {}
BINARYNINJACOREAPI void BNSetTypeBuilderAttribute(BNTypeBuilder* type,
                                                  const char* name,
                                                  const char* value) {}
BINARYNINJACOREAPI void BNSetTypeBuilderAttributeList(BNTypeBuilder* type,
                                                      BNTypeAttribute* attrs,
                                                      size_t count) {}
BINARYNINJACOREAPI void BNRemoveTypeBuilderAttribute(BNTypeBuilder* type,
                                                     const char* name) {}
BINARYNINJACOREAPI BNTypeAttribute* BNGetTypeBuilderAttributes(
    BNTypeBuilder* type, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderAttributeByName(BNTypeBuilder* type,
                                                         const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderString(BNTypeBuilder* type,
                                                BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderStringBeforeName(
    BNTypeBuilder* type, BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeBuilderStringAfterName(BNTypeBuilder* type,
                                                         BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeBuilderTokens(
    BNTypeBuilder* type, BNPlatform* platform, uint8_t baseConfidence,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeBuilderTokensBeforeName(
    BNTypeBuilder* type, BNPlatform* platform, uint8_t baseConfidence,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetTypeBuilderTokensAfterName(
    BNTypeBuilder* type, BNPlatform* platform, uint8_t baseConfidence,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateNamedTypeReference(
    BNNamedTypeReference* nt, size_t width, size_t align,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateNamedTypeReferenceFromTypeAndId(
    const char* id, BNQualifiedName* name, BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNType* BNCreateNamedTypeReferenceFromType(
    BNBinaryView* view, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateNamedTypeReferenceBuilder(
    BNNamedTypeReference* nt, size_t width, size_t align,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateNamedTypeReferenceBuilderWithBuilder(
    BNNamedTypeReferenceBuilder* nt, size_t width, size_t align,
    BNBoolWithConfidence* cnst, BNBoolWithConfidence* vltl) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder*
BNCreateNamedTypeReferenceBuilderFromTypeAndId(const char* id,
                                               BNQualifiedName* name,
                                               BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNTypeBuilder* BNCreateNamedTypeReferenceBuilderFromType(
    BNBinaryView* view, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReference* BNCreateNamedType(
    BNNamedTypeReferenceClass cls, const char* id, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReferenceClass
BNGetTypeReferenceClass(BNNamedTypeReference* nt) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeReferenceId(BNNamedTypeReference* nt) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName
BNGetTypeReferenceName(BNNamedTypeReference* nt) {
  return {};
}
BINARYNINJACOREAPI void BNFreeQualifiedName(BNQualifiedName* name) {}
BINARYNINJACOREAPI void BNFreeQualifiedNameArray(BNQualifiedName* names,
                                                 size_t count) {}
BINARYNINJACOREAPI void BNFreeNamedTypeReference(BNNamedTypeReference* nt) {}
BINARYNINJACOREAPI BNNamedTypeReference* BNNewNamedTypeReference(
    BNNamedTypeReference* nt) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReferenceBuilder* BNCreateNamedTypeBuilder(
    BNNamedTypeReferenceClass cls, const char* id, BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI void BNFreeNamedTypeReferenceBuilder(
    BNNamedTypeReferenceBuilder* s) {}
BINARYNINJACOREAPI void BNSetNamedTypeReferenceBuilderTypeClass(
    BNNamedTypeReferenceBuilder* s, BNNamedTypeReferenceClass type) {}
BINARYNINJACOREAPI void BNSetNamedTypeReferenceBuilderTypeId(
    BNNamedTypeReferenceBuilder* s, const char* id) {}
BINARYNINJACOREAPI void BNSetNamedTypeReferenceBuilderName(
    BNNamedTypeReferenceBuilder* s, BNQualifiedName* name) {}
BINARYNINJACOREAPI BNNamedTypeReference* BNFinalizeNamedTypeReferenceBuilder(
    BNNamedTypeReferenceBuilder* s) {
  return {};
}
BINARYNINJACOREAPI BNNamedTypeReferenceClass
BNGetTypeReferenceBuilderClass(BNNamedTypeReferenceBuilder* nt) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeReferenceBuilderId(
    BNNamedTypeReferenceBuilder* nt) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName
BNGetTypeReferenceBuilderName(BNNamedTypeReferenceBuilder* nt) {
  return {};
}
BINARYNINJACOREAPI void BNSetNamedTypeReferenceBuilder(
    BNTypeBuilder* type, BNNamedTypeReferenceBuilder* nt) {}
BINARYNINJACOREAPI BNStructureBuilder* BNCreateStructureBuilder(void) {
  return {};
}
BINARYNINJACOREAPI BNStructureBuilder* BNCreateStructureBuilderWithOptions(
    BNStructureVariant type, bool packed) {
  return {};
}
BINARYNINJACOREAPI BNStructureBuilder* BNCreateStructureBuilderFromStructure(
    BNStructure* s) {
  return {};
}
BINARYNINJACOREAPI BNStructureBuilder* BNDuplicateStructureBuilder(
    BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNFinalizeStructureBuilder(
    BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNNewStructureReference(BNStructure* s) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStructure(BNStructure* s) {}
BINARYNINJACOREAPI void BNFreeStructureBuilder(BNStructureBuilder* s) {}
BINARYNINJACOREAPI void BNSetStructureBuilder(BNTypeBuilder* type,
                                              BNStructureBuilder* s) {}
BINARYNINJACOREAPI BNStructureMember* BNGetStructureMemberByName(
    BNStructure* s, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNStructureMember* BNGetStructureMemberAtOffset(
    BNStructure* s, int64_t offset, size_t* idx) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStructureMember(BNStructureMember* s) {}
BINARYNINJACOREAPI BNStructureMember* BNGetStructureMembers(BNStructure* s,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStructureMemberList(BNStructureMember* members,
                                                  size_t count) {}
BINARYNINJACOREAPI BNInheritedStructureMember*
BNGetStructureMembersIncludingInherited(BNStructure* s, BNTypeContainer* types,
                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeInheritedStructureMemberList(
    BNInheritedStructureMember* members, size_t count) {}
BINARYNINJACOREAPI BNInheritedStructureMember*
BNGetMemberIncludingInheritedAtOffset(BNStructure* s, BNBinaryView* view,
                                      int64_t offset) {
  return {};
}
BINARYNINJACOREAPI void BNFreeInheritedStructureMember(
    BNInheritedStructureMember* members) {}
BINARYNINJACOREAPI uint64_t BNGetStructureWidth(BNStructure* s) { return {}; }
BINARYNINJACOREAPI int64_t BNGetStructurePointerOffset(BNStructure* s) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetStructureAlignment(BNStructure* s) { return {}; }
BINARYNINJACOREAPI bool BNIsStructurePacked(BNStructure* s) { return {}; }
BINARYNINJACOREAPI bool BNIsStructureUnion(BNStructure* s) { return {}; }
BINARYNINJACOREAPI bool BNStructurePropagatesDataVariableReferences(
    BNStructure* s) {
  return {};
}
BINARYNINJACOREAPI BNStructureVariant BNGetStructureType(BNStructure* s) {
  return {};
}
BINARYNINJACOREAPI BNBaseStructure* BNGetBaseStructuresForStructure(
    BNStructure* s, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBaseStructureList(BNBaseStructure* bases,
                                                size_t count) {}
BINARYNINJACOREAPI bool BNResolveStructureMemberOrBaseMember(
    BNStructure* s, BNBinaryView* data, uint64_t offset, size_t size,
    void* callbackContext,
    void (*resolveFunc)(void* ctxt, BNNamedTypeReference* baseName,
                        BNStructure* resolvedStruct, size_t memberIndex,
                        uint64_t structOffset, uint64_t adjustedOffset,
                        BNStructureMember member),
    bool memberIndexHintValid, size_t memberIndexHint) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNStructureWithReplacedStructure(
    BNStructure* s, BNStructure* from, BNStructure* to) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNStructureWithReplacedEnumeration(
    BNStructure* s, BNEnumeration* from, BNEnumeration* to) {
  return {};
}
BINARYNINJACOREAPI BNStructure* BNStructureWithReplacedNamedTypeReference(
    BNStructure* s, BNNamedTypeReference* from, BNNamedTypeReference* to) {
  return {};
}
BINARYNINJACOREAPI BNStructureMember* BNGetStructureBuilderMemberByName(
    BNStructureBuilder* s, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNStructureMember* BNGetStructureBuilderMemberAtOffset(
    BNStructureBuilder* s, int64_t offset, size_t* idx) {
  return {};
}
BINARYNINJACOREAPI BNStructureMember* BNGetStructureBuilderMembers(
    BNStructureBuilder* s, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNGetStructureBuilderWidth(BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI void BNSetStructureBuilderWidth(BNStructureBuilder* s,
                                                   uint64_t width) {}
BINARYNINJACOREAPI int64_t
BNGetStructureBuilderPointerOffset(BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI void BNSetStructureBuilderPointerOffset(
    BNStructureBuilder* s, int64_t offset) {}
BINARYNINJACOREAPI size_t
BNGetStructureBuilderAlignment(BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI void BNSetStructureBuilderAlignment(BNStructureBuilder* s,
                                                       size_t align) {}
BINARYNINJACOREAPI bool BNIsStructureBuilderPacked(BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI void BNSetStructureBuilderPacked(BNStructureBuilder* s,
                                                    bool packed) {}
BINARYNINJACOREAPI bool BNIsStructureBuilderUnion(BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI void BNSetStructureBuilderType(BNStructureBuilder* s,
                                                  BNStructureVariant type) {}
BINARYNINJACOREAPI bool BNStructureBuilderPropagatesDataVariableReferences(
    BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI void BNSetStructureBuilderPropagatesDataVariableReferences(
    BNStructureBuilder* s, bool value) {}
BINARYNINJACOREAPI BNStructureVariant
BNGetStructureBuilderType(BNStructureBuilder* s) {
  return {};
}
BINARYNINJACOREAPI BNBaseStructure* BNGetBaseStructuresForStructureBuilder(
    BNStructureBuilder* s, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNSetBaseStructuresForStructureBuilder(
    BNStructureBuilder* s, BNBaseStructure* bases, size_t count) {}
BINARYNINJACOREAPI void BNAddStructureBuilderMember(
    BNStructureBuilder* s, const BNTypeWithConfidence* const type,
    const char* name, BNMemberAccess access, BNMemberScope scope) {}
BINARYNINJACOREAPI void BNAddStructureBuilderMemberAtOffset(
    BNStructureBuilder* s, const BNTypeWithConfidence* const type,
    const char* name, uint64_t offset, bool overwriteExisting,
    BNMemberAccess access, BNMemberScope scope, uint8_t bitPosition,
    uint8_t bitWidth) {}
BINARYNINJACOREAPI void BNRemoveStructureBuilderMember(BNStructureBuilder* s,
                                                       size_t idx) {}
BINARYNINJACOREAPI void BNReplaceStructureBuilderMember(
    BNStructureBuilder* s, size_t idx, const BNTypeWithConfidence* const type,
    const char* name, bool overwriteExisting) {}
BINARYNINJACOREAPI BNEnumerationBuilder* BNCreateEnumerationBuilder(void) {
  return {};
}
BINARYNINJACOREAPI BNEnumerationBuilder*
BNCreateEnumerationBuilderFromEnumeration(BNEnumeration* e) {
  return {};
}
BINARYNINJACOREAPI BNEnumerationBuilder* BNDuplicateEnumerationBuilder(
    BNEnumerationBuilder* e) {
  return {};
}
BINARYNINJACOREAPI BNEnumeration* BNFinalizeEnumerationBuilder(
    BNEnumerationBuilder* e) {
  return {};
}
BINARYNINJACOREAPI BNEnumeration* BNNewEnumerationReference(BNEnumeration* e) {
  return {};
}
BINARYNINJACOREAPI void BNFreeEnumeration(BNEnumeration* e) {}
BINARYNINJACOREAPI void BNFreeEnumerationBuilder(BNEnumerationBuilder* e) {}
BINARYNINJACOREAPI void BNSetEnumerationBuilder(BNTypeBuilder* type,
                                                BNEnumerationBuilder* e) {}
BINARYNINJACOREAPI BNEnumerationMember* BNGetEnumerationMembers(
    BNEnumeration* e, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken* BNGetEnumerationTokensForValue(
    BNEnumeration* e, uint64_t value, uint64_t width, size_t* count,
    BNType* type) {
  return {};
}
BINARYNINJACOREAPI void BNFreeEnumerationMemberList(
    BNEnumerationMember* members, size_t count) {}
BINARYNINJACOREAPI BNEnumerationMember* BNGetEnumerationBuilderMembers(
    BNEnumerationBuilder* e, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddEnumerationBuilderMember(BNEnumerationBuilder* e,
                                                      const char* name) {}
BINARYNINJACOREAPI void BNAddEnumerationBuilderMemberWithValue(
    BNEnumerationBuilder* e, const char* name, uint64_t value) {}
BINARYNINJACOREAPI void BNRemoveEnumerationBuilderMember(
    BNEnumerationBuilder* e, size_t idx) {}
BINARYNINJACOREAPI void BNReplaceEnumerationBuilderMember(
    BNEnumerationBuilder* e, size_t idx, const char* name, uint64_t value) {}
BINARYNINJACOREAPI BNStructure* BNCreateStructureFromOffsetAccess(
    BNBinaryView* view, BNQualifiedName* name, bool* newMember) {
  return {};
}
BINARYNINJACOREAPI BNTypeWithConfidence BNCreateStructureMemberFromAccess(
    BNBinaryView* view, BNQualifiedName* name, uint64_t offset) {
  return {};
}
BINARYNINJACOREAPI void BNAddExpressionParserMagicValue(BNBinaryView* view,
                                                        const char* name,
                                                        uint64_t value) {}
BINARYNINJACOREAPI void BNRemoveExpressionParserMagicValue(BNBinaryView* view,
                                                           const char* name) {}
BINARYNINJACOREAPI void BNAddExpressionParserMagicValues(BNBinaryView* view,
                                                         const char** names,
                                                         uint64_t* values,
                                                         size_t count) {}
BINARYNINJACOREAPI void BNRemoveExpressionParserMagicValues(BNBinaryView* view,
                                                            const char** names,
                                                            size_t count) {}
BINARYNINJACOREAPI bool BNGetExpressionParserMagicValue(BNBinaryView* view,
                                                        const char* name,
                                                        uint64_t* value) {
  return {};
}
BINARYNINJACOREAPI BNComponent** BNGetFunctionParentComponents(
    BNBinaryView* view, BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNComponent** BNGetDataVariableParentComponents(
    BNBinaryView* view, uint64_t dataVariable, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNCheckForStringAnnotationType(
    BNBinaryView* view, uint64_t addr, char** value, BNStringType* strType,
    bool allowShortStrings, bool allowLargeStrings, size_t childWidth) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNLoadFilename(const char* const filename,
                                                const bool updateAnalysis,
                                                const char* options,
                                                BNProgressFunction progress,
                                                void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNLoadProjectFile(BNProjectFile* projectFile,
                                                   const bool updateAnalysis,
                                                   const char* options,
                                                   BNProgressFunction progress,
                                                   void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNLoadBinaryView(BNBinaryView* view,
                                                  const bool updateAnalysis,
                                                  const char* options,
                                                  BNProgressFunction progress,
                                                  void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNParseTextFormat(const char* filename) {
  return {};
}
BINARYNINJACOREAPI BNExternalLibrary* BNBinaryViewAddExternalLibrary(
    BNBinaryView* view, const char* name, BNProjectFile* backingFile,
    bool isAuto) {
  return {};
}
BINARYNINJACOREAPI void BNBinaryViewRemoveExternalLibrary(BNBinaryView* view,
                                                          const char* name) {}
BINARYNINJACOREAPI BNExternalLibrary* BNBinaryViewGetExternalLibrary(
    BNBinaryView* view, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNExternalLibrary** BNBinaryViewGetExternalLibraries(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNExternalLocation* BNBinaryViewAddExternalLocation(
    BNBinaryView* view, BNSymbol* sourceSymbol, BNExternalLibrary* library,
    const char* targetSymbol, uint64_t* targetAddress, bool isAuto) {
  return {};
}
BINARYNINJACOREAPI void BNBinaryViewRemoveExternalLocation(
    BNBinaryView* view, BNSymbol* sourceSymbol) {}
BINARYNINJACOREAPI BNExternalLocation* BNBinaryViewGetExternalLocation(
    BNBinaryView* view, BNSymbol* sourceSymbol) {
  return {};
}
BINARYNINJACOREAPI BNExternalLocation** BNBinaryViewGetExternalLocations(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNPreprocessSource(const char* source,
                                           const char* fileName, char** output,
                                           char** errors,
                                           const char** includeDirs,
                                           size_t includeDirCount) {
  return {};
}
BINARYNINJACOREAPI bool BNParseTypesFromSource(
    BNPlatform* platform, const char* source, const char* fileName,
    BNTypeParserResult* result, char** errors, const char** includeDirs,
    size_t includeDirCount, const char* autoTypeSource) {
  return {};
}
BINARYNINJACOREAPI bool BNParseTypesFromSourceFile(
    BNPlatform* platform, const char* fileName, BNTypeParserResult* result,
    char** errors, const char** includeDirs, size_t includeDirCount,
    const char* autoTypeSource) {
  return {};
}
BINARYNINJACOREAPI BNTypeParser* BNRegisterTypeParser(
    const char* name, BNTypeParserCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNTypeParser** BNGetTypeParserList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeParserList(BNTypeParser** parsers) {}
BINARYNINJACOREAPI BNTypeParser* BNGetTypeParserByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNTypeParser* BNGetDefaultTypeParser(void) { return {}; }
BINARYNINJACOREAPI char* BNGetTypeParserName(BNTypeParser* parser) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypeParserOptionText(BNTypeParser* parser,
                                                  BNTypeParserOption option,
                                                  const char* value,
                                                  char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeParserPreprocessSource(
    BNTypeParser* parser, const char* source, const char* fileName,
    BNPlatform* platform, BNTypeContainer* existingTypes,
    const char* const* options, size_t optionCount,
    const char* const* includeDirs, size_t includeDirCount, char** output,
    BNTypeParserError** errors, size_t* errorCount) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeParserParseTypesFromSource(
    BNTypeParser* parser, const char* source, const char* fileName,
    BNPlatform* platform, BNTypeContainer* existingTypes,
    const char* const* options, size_t optionCount,
    const char* const* includeDirs, size_t includeDirCount,
    const char* autoTypeSource, BNTypeParserResult* result,
    BNTypeParserError** errors, size_t* errorCount) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeParserParseTypeString(
    BNTypeParser* parser, const char* source, BNPlatform* platform,
    BNTypeContainer* existingTypes, BNQualifiedNameAndType* result,
    BNTypeParserError** errors, size_t* errorCount) {
  return {};
}
BINARYNINJACOREAPI char** BNParseTypeParserOptionsText(const char* optionsText,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNFormatTypeParserParseErrors(
    BNTypeParserError* errors, size_t count) {
  return {};
}
BINARYNINJACOREAPI BNTypePrinter* BNRegisterTypePrinter(
    const char* name, BNTypePrinterCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNTypePrinter** BNGetTypePrinterList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypePrinterList(BNTypePrinter** printers) {}
BINARYNINJACOREAPI BNTypePrinter* BNGetTypePrinterByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypePrinterName(BNTypePrinter* printer) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeTokens(
    BNTypePrinter* printer, BNType* type, BNPlatform* platform,
    BNQualifiedName* name, uint8_t baseConfidence, BNTokenEscapingType escaping,
    BNInstructionTextToken** result, size_t* resultCount) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeTokensBeforeName(
    BNTypePrinter* printer, BNType* type, BNPlatform* platform,
    uint8_t baseConfidence, BNType* parentType, BNTokenEscapingType escaping,
    BNInstructionTextToken** result, size_t* resultCount) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeTokensAfterName(
    BNTypePrinter* printer, BNType* type, BNPlatform* platform,
    uint8_t baseConfidence, BNType* parentType, BNTokenEscapingType escaping,
    BNInstructionTextToken** result, size_t* resultCount) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeString(
    BNTypePrinter* printer, BNType* type, BNPlatform* platform,
    BNQualifiedName* name, BNTokenEscapingType escaping, char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeStringBeforeName(
    BNTypePrinter* printer, BNType* type, BNPlatform* platform,
    BNTokenEscapingType escaping, char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeStringAfterName(
    BNTypePrinter* printer, BNType* type, BNPlatform* platform,
    BNTokenEscapingType escaping, char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypePrinterTypeLines(
    BNTypePrinter* printer, BNType* type, BNTypeContainer* types,
    BNQualifiedName* name, int paddingCols, bool collapsed,
    BNTokenEscapingType escaping, BNTypeDefinitionLine** result,
    size_t* resultCount) {
  return {};
}
BINARYNINJACOREAPI bool BNTypePrinterPrintAllTypes(
    BNTypePrinter* printer, BNQualifiedName* names, BNType** types,
    size_t typeCount, BNBinaryView* data, int paddingCols,
    BNTokenEscapingType escaping, char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNTypePrinterDefaultPrintAllTypes(
    BNTypePrinter* printer, BNQualifiedName* names, BNType** types,
    size_t typeCount, BNBinaryView* data, int paddingCols,
    BNTokenEscapingType escaping, char** result) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeParserResult(BNTypeParserResult* result) {}
BINARYNINJACOREAPI void BNFreeTypeParserErrors(BNTypeParserError* errors,
                                               size_t count) {}
BINARYNINJACOREAPI BNUpdateChannel* BNGetUpdateChannels(size_t* count,
                                                        char** errors) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUpdateChannelList(BNUpdateChannel* list,
                                                size_t count) {}
BINARYNINJACOREAPI BNUpdateVersion* BNGetUpdateChannelVersions(
    const char* channel, size_t* count, char** errors) {
  return {};
}
BINARYNINJACOREAPI void BNFreeUpdateChannelVersionList(BNUpdateVersion* list,
                                                       size_t count) {}
BINARYNINJACOREAPI BNUpdateChannelFullInfo* BNGetFullInfoUpdateChannels(
    size_t* count, char** errors) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFullInfoUpdateChannels(
    BNUpdateChannelFullInfo* list, size_t count) {}
BINARYNINJACOREAPI bool BNAreUpdatesAvailable(const char* channel,
                                              uint64_t* expireTime,
                                              uint64_t* serverTime,
                                              char** errors) {
  return {};
}
BINARYNINJACOREAPI BNUpdateResult BNUpdateToVersion(const char* channel,
                                                    const char* version,
                                                    char** errors,
                                                    BNProgressFunction progress,
                                                    void* context) {
  return {};
}
BINARYNINJACOREAPI BNUpdateResult
BNUpdateToLatestVersion(const char* channel, char** errors,
                        BNProgressFunction progress, void* context) {
  return {};
}
BINARYNINJACOREAPI bool BNAreAutoUpdatesEnabled(void) { return {}; }
BINARYNINJACOREAPI void BNSetAutoUpdatesEnabled(bool enabled) {}
BINARYNINJACOREAPI uint64_t BNGetTimeSinceLastUpdateCheck(void) { return {}; }
BINARYNINJACOREAPI void BNUpdatesChecked(void) {}
BINARYNINJACOREAPI char* BNGetActiveUpdateChannel(void) { return {}; }
BINARYNINJACOREAPI void BNSetActiveUpdateChannel(const char* channel) {}
BINARYNINJACOREAPI bool BNIsUpdateInstallationPending(void) { return {}; }
BINARYNINJACOREAPI void BNInstallPendingUpdate(char** errors) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandGlobal(
    const char* name, const char* description, void (*action)(void* ctxt),
    bool (*isValid)(void* ctxt), void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommand(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view),
    bool (*isValid)(void* ctxt, BNBinaryView* view), void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForAddress(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, uint64_t addr),
    bool (*isValid)(void* ctxt, BNBinaryView* view, uint64_t addr),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForRange(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, uint64_t addr, uint64_t len),
    bool (*isValid)(void* ctxt, BNBinaryView* view, uint64_t addr,
                    uint64_t len),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForFunction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, BNFunction* func),
    bool (*isValid)(void* ctxt, BNBinaryView* view, BNFunction* func),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForLowLevelILFunction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, BNLowLevelILFunction* func),
    bool (*isValid)(void* ctxt, BNBinaryView* view, BNLowLevelILFunction* func),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForLowLevelILInstruction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, BNLowLevelILFunction* func,
                   size_t instr),
    bool (*isValid)(void* ctxt, BNBinaryView* view, BNLowLevelILFunction* func,
                    size_t instr),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForMediumLevelILFunction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view,
                   BNMediumLevelILFunction* func),
    bool (*isValid)(void* ctxt, BNBinaryView* view,
                    BNMediumLevelILFunction* func),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForMediumLevelILInstruction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view,
                   BNMediumLevelILFunction* func, size_t instr),
    bool (*isValid)(void* ctxt, BNBinaryView* view,
                    BNMediumLevelILFunction* func, size_t instr),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForHighLevelILFunction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, BNHighLevelILFunction* func),
    bool (*isValid)(void* ctxt, BNBinaryView* view,
                    BNHighLevelILFunction* func),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForHighLevelILInstruction(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNBinaryView* view, BNHighLevelILFunction* func,
                   size_t instr),
    bool (*isValid)(void* ctxt, BNBinaryView* view, BNHighLevelILFunction* func,
                    size_t instr),
    void* context) {}
BINARYNINJACOREAPI void BNRegisterPluginCommandForProject(
    const char* name, const char* description,
    void (*action)(void* ctxt, BNProject* project),
    bool (*isValid)(void* ctxt, BNProject* project), void* context) {}
BINARYNINJACOREAPI BNPluginCommand* BNGetAllPluginCommands(size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand* BNGetValidPluginCommandsGlobal(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand* BNGetValidPluginCommands(BNBinaryView* view,
                                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand* BNGetValidPluginCommandsForAddress(
    BNBinaryView* view, uint64_t addr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand* BNGetValidPluginCommandsForRange(
    BNBinaryView* view, uint64_t addr, uint64_t len, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand* BNGetValidPluginCommandsForFunction(
    BNBinaryView* view, BNFunction* func, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand*
BNGetValidPluginCommandsForLowLevelILFunction(BNBinaryView* view,
                                              BNLowLevelILFunction* func,
                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand*
BNGetValidPluginCommandsForLowLevelILInstruction(BNBinaryView* view,
                                                 BNLowLevelILFunction* func,
                                                 size_t instr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand*
BNGetValidPluginCommandsForMediumLevelILFunction(BNBinaryView* view,
                                                 BNMediumLevelILFunction* func,
                                                 size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand*
BNGetValidPluginCommandsForMediumLevelILInstruction(
    BNBinaryView* view, BNMediumLevelILFunction* func, size_t instr,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand*
BNGetValidPluginCommandsForHighLevelILFunction(BNBinaryView* view,
                                               BNHighLevelILFunction* func,
                                               size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand*
BNGetValidPluginCommandsForHighLevelILInstruction(BNBinaryView* view,
                                                  BNHighLevelILFunction* func,
                                                  size_t instr, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginCommand* BNGetValidPluginCommandsForProject(
    BNProject* project, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePluginCommandList(BNPluginCommand* commands) {}
BINARYNINJACOREAPI BNCallingConvention* BNCreateCallingConvention(
    BNArchitecture* arch, const char* name, BNCustomCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterCallingConvention(BNArchitecture* arch,
                                                    BNCallingConvention* cc) {}
BINARYNINJACOREAPI BNCallingConvention* BNNewCallingConventionReference(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCallingConvention(BNCallingConvention* cc) {}
BINARYNINJACOREAPI BNCallingConvention** BNGetArchitectureCallingConventions(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCallingConventionList(BNCallingConvention** list,
                                                    size_t count) {}
BINARYNINJACOREAPI BNCallingConvention*
BNGetArchitectureCallingConventionByName(BNArchitecture* arch,
                                         const char* name) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNGetCallingConventionArchitecture(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI char* BNGetCallingConventionName(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetCallerSavedRegisters(BNCallingConvention* cc,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetCalleeSavedRegisters(BNCallingConvention* cc,
                                                       size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetIntegerArgumentRegisters(
    BNCallingConvention* cc, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetFloatArgumentRegisters(
    BNCallingConvention* cc, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetRequiredArgumentRegisters(
    BNCallingConvention* cc, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetRequiredClobberedRegisters(
    BNCallingConvention* cc, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNAreArgumentRegistersSharedIndex(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI bool BNAreArgumentRegistersUsedForVarArgs(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI bool BNIsStackReservedForArgumentRegisters(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI bool BNIsStackAdjustedOnReturn(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI bool BNIsEligibleForHeuristics(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetIntegerReturnValueRegister(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetHighIntegerReturnValueRegister(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI uint32_t
BNGetFloatReturnValueRegister(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetGlobalPointerRegisters(
    BNCallingConvention* cc, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint32_t* BNGetImplicitlyDefinedRegisters(
    BNCallingConvention* cc, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetIncomingRegisterValue(
    BNCallingConvention* cc, uint32_t reg, BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNRegisterValue BNGetIncomingFlagValue(
    BNCallingConvention* cc, uint32_t reg, BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNCallLayout
BNGetCallLayout(BNCallingConvention* cc, BNBinaryView* view,
                const BNReturnValue* returnValue,
                const BNFunctionParameter* params, size_t paramCount,
                const uint32_t* permittedRegs, size_t permittedRegCount) {
  return {};
}
BINARYNINJACOREAPI BNCallLayout BNGetCallLayoutDefaultPermittedArgs(
    BNCallingConvention* cc, BNBinaryView* view,
    const BNReturnValue* returnValue, const BNFunctionParameter* params,
    size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI BNCallLayout BNGetDefaultCallLayout(
    BNCallingConvention* cc, BNBinaryView* view,
    const BNReturnValue* returnValue, const BNFunctionParameter* params,
    size_t paramCount, const uint32_t* permittedRegs,
    size_t permittedRegCount) {
  return {};
}
BINARYNINJACOREAPI BNCallLayout BNGetDefaultCallLayoutDefaultPermittedArgs(
    BNCallingConvention* cc, BNBinaryView* view,
    const BNReturnValue* returnValue, const BNFunctionParameter* params,
    size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCallLayout(BNCallLayout* layout) {}
BINARYNINJACOREAPI BNValueLocation BNGetReturnValueLocation(
    BNCallingConvention* cc, BNBinaryView* view, BNReturnValue* returnValue) {
  return {};
}
BINARYNINJACOREAPI BNValueLocation BNGetDefaultReturnValueLocation(
    BNCallingConvention* cc, BNBinaryView* view, BNReturnValue* returnValue) {
  return {};
}
BINARYNINJACOREAPI BNValueLocation* BNGetParameterLocations(
    BNCallingConvention* cc, BNBinaryView* view, BNValueLocation* returnValue,
    BNFunctionParameter* params, size_t paramCount,
    const uint32_t* permittedRegs, size_t permittedRegCount, size_t* outCount) {
  return {};
}
BINARYNINJACOREAPI BNValueLocation* BNGetParameterLocationsDefaultPermittedArgs(
    BNCallingConvention* cc, BNBinaryView* view, BNValueLocation* returnValue,
    BNFunctionParameter* params, size_t paramCount, size_t* outCount) {
  return {};
}
BINARYNINJACOREAPI BNValueLocation* BNGetDefaultParameterLocations(
    BNCallingConvention* cc, BNBinaryView* view, BNValueLocation* returnValue,
    BNFunctionParameter* params, size_t paramCount,
    const uint32_t* permittedRegs, size_t permittedRegCount, size_t* outCount) {
  return {};
}
BINARYNINJACOREAPI BNValueLocation*
BNGetDefaultParameterLocationsDefaultPermittedArgs(
    BNCallingConvention* cc, BNBinaryView* view, BNValueLocation* returnValue,
    BNFunctionParameter* params, size_t paramCount, size_t* outCount) {
  return {};
}
BINARYNINJACOREAPI void BNFreeValueLocationList(BNValueLocation* locations,
                                                size_t count) {}
BINARYNINJACOREAPI BNVariable* BNGetParameterOrderingForVariables(
    BNCallingConvention* cc, BNBinaryView* view, const BNVariable* paramVars,
    const BNType** paramTypes, size_t paramCount, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNVariable* BNGetDefaultParameterOrderingForVariables(
    BNCallingConvention* cc, const BNVariable* paramVars,
    const BNType** paramTypes, size_t paramCount, size_t* count) {
  return {};
}
BINARYNINJACOREAPI int64_t BNGetStackAdjustmentForLocations(
    BNCallingConvention* cc, BNBinaryView* view, BNValueLocation* returnValue,
    const BNValueLocation* paramLocations, const BNType** paramTypes,
    size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI int64_t BNGetDefaultStackAdjustmentForLocations(
    BNCallingConvention* cc, BNValueLocation* returnValue,
    const BNValueLocation* paramLocations, const BNType** paramTypes,
    size_t paramCount) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetCallingConventionRegisterStackAdjustments(
    BNCallingConvention* cc, BNBinaryView* view, BNValueLocation* returnValue,
    BNValueLocation* params, size_t paramCount, uint32_t** outRegs,
    int32_t** outAdjust) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetCallingConventionDefaultRegisterStackAdjustments(
    BNCallingConvention* cc, BNValueLocation* returnValue,
    BNValueLocation* params, size_t paramCount, uint32_t** outRegs,
    int32_t** outAdjust) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCallingConventionRegisterStackAdjustments(
    uint32_t* regs, int32_t* adjust) {}
BINARYNINJACOREAPI BNVariable BNGetIncomingVariableForParameterVariable(
    BNCallingConvention* cc, const BNVariable* var, BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNVariable BNGetParameterVariableForIncomingVariable(
    BNCallingConvention* cc, const BNVariable* var, BNFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNVariable BNGetDefaultIncomingVariableForParameterVariable(
    BNCallingConvention* cc, const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI BNVariable BNGetDefaultParameterVariableForIncomingVariable(
    BNCallingConvention* cc, const BNVariable* var) {
  return {};
}
BINARYNINJACOREAPI bool BNIsReturnTypeRegisterCompatible(
    BNCallingConvention* cc, BNBinaryView* view, BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNDefaultIsReturnTypeRegisterCompatible(
    BNCallingConvention* cc, BNType* type) {
  return {};
}
BINARYNINJACOREAPI BNVariable
BNGetIndirectReturnValueLocation(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI BNVariable
BNGetDefaultIndirectReturnValueLocation(BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI bool BNGetReturnedIndirectReturnValuePointer(
    BNCallingConvention* cc, BNVariable* outVar) {
  return {};
}
BINARYNINJACOREAPI bool BNIsArgumentTypeRegisterCompatible(
    BNCallingConvention* cc, BNBinaryView* view, BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNDefaultIsArgumentTypeRegisterCompatible(
    BNCallingConvention* cc, BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNIsNonRegisterArgumentIndirect(BNCallingConvention* cc,
                                                        BNBinaryView* view,
                                                        BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNAreStackArgumentsNaturallyAligned(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI bool BNAreStackArgumentsPushedLeftToRight(
    BNCallingConvention* cc) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention*
BNGetArchitectureDefaultCallingConvention(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention* BNGetArchitectureCdeclCallingConvention(
    BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention*
BNGetArchitectureStdcallCallingConvention(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention*
BNGetArchitectureFastcallCallingConvention(BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNSetArchitectureDefaultCallingConvention(
    BNArchitecture* arch, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNSetArchitectureCdeclCallingConvention(
    BNArchitecture* arch, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNSetArchitectureStdcallCallingConvention(
    BNArchitecture* arch, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNSetArchitectureFastcallCallingConvention(
    BNArchitecture* arch, BNCallingConvention* cc) {}
BINARYNINJACOREAPI BNPlatform* BNCreatePlatform(BNArchitecture* arch,
                                                const char* name) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNCreatePlatformWithTypes(
    BNArchitecture* arch, const char* name, const char* typeFile,
    const char** includeDirs, size_t includeDirCount) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNCreateCustomPlatform(BNArchitecture* arch,
                                                      const char* name,
                                                      BNCustomPlatform* impl) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNCreateCustomPlatformWithTypes(
    BNArchitecture* arch, const char* name, BNCustomPlatform* impl,
    const char* typeFile, const char** includeDirs, size_t includeDirCount) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterPlatform(const char* os,
                                           BNPlatform* platform) {}
BINARYNINJACOREAPI BNPlatform* BNNewPlatformReference(BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI void BNFreePlatform(BNPlatform* platform) {}
BINARYNINJACOREAPI char* BNGetPlatformName(BNPlatform* platform) { return {}; }
BINARYNINJACOREAPI BNArchitecture* BNGetPlatformArchitecture(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNGetPlatformByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNPlatform** BNGetPlatformList(size_t* count) { return {}; }
BINARYNINJACOREAPI BNPlatform** BNGetPlatformListByArchitecture(
    BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPlatform** BNGetPlatformListByOS(const char* os,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPlatform** BNGetPlatformListByOSAndArchitecture(
    const char* os, BNArchitecture* arch, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePlatformList(BNPlatform** platform,
                                           size_t count) {}
BINARYNINJACOREAPI char** BNGetPlatformOSList(size_t* count) { return {}; }
BINARYNINJACOREAPI void BNFreePlatformOSList(char** list, size_t count) {}
BINARYNINJACOREAPI BNCallingConvention* BNGetPlatformDefaultCallingConvention(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention* BNGetPlatformCdeclCallingConvention(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention* BNGetPlatformStdcallCallingConvention(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention* BNGetPlatformFastcallCallingConvention(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention** BNGetPlatformCallingConventions(
    BNPlatform* platform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCallingConvention* BNGetPlatformSystemCallConvention(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterPlatformCallingConvention(
    BNPlatform* platform, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNRegisterPlatformDefaultCallingConvention(
    BNPlatform* platform, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNRegisterPlatformCdeclCallingConvention(
    BNPlatform* platform, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNRegisterPlatformStdcallCallingConvention(
    BNPlatform* platform, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNRegisterPlatformFastcallCallingConvention(
    BNPlatform* platform, BNCallingConvention* cc) {}
BINARYNINJACOREAPI void BNSetPlatformSystemCallConvention(
    BNPlatform* platform, BNCallingConvention* cc) {}
BINARYNINJACOREAPI uint32_t* BNGetPlatformGlobalRegisters(BNPlatform* platform,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetPlatformGlobalRegisterType(BNPlatform* platform,
                                                           uint32_t reg) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetPlatformAddressSize(BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI void BNPlatformAdjustTypeParserInput(
    BNPlatform* platform, BNTypeParser* parser, const char* const* argumentsIn,
    size_t argumentsLenIn, const char* const* sourceFileNamesIn,
    const char* const* sourceFileValuesIn, size_t sourceFilesLenIn,
    char*** argumentsOut, size_t* argumentsLenOut, char*** sourceFileNamesOut,
    char*** sourceFileValuesOut, size_t* sourceFilesLenOut) {}
BINARYNINJACOREAPI BNPlatform* BNGetArchitectureStandalonePlatform(
    BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNGetRelatedPlatform(BNPlatform* platform,
                                                    BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNAddRelatedPlatform(BNPlatform* platform,
                                             BNArchitecture* arch,
                                             BNPlatform* related) {}
BINARYNINJACOREAPI BNPlatform** BNGetRelatedPlatforms(BNPlatform* platform,
                                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNGetAssociatedPlatformByAddress(
    BNPlatform* platform, uint64_t* addr) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainer* BNGetPlatformTypeContainer(
    BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType* BNGetPlatformTypes(
    BNPlatform* platform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType* BNGetPlatformVariables(
    BNPlatform* platform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameAndType* BNGetPlatformFunctions(
    BNPlatform* platform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSystemCallInfo* BNGetPlatformSystemCalls(
    BNPlatform* platform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSystemCallList(BNSystemCallInfo* syscalls,
                                             size_t count) {}
BINARYNINJACOREAPI BNType* BNGetPlatformTypeByName(BNPlatform* platform,
                                                   BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetPlatformVariableByName(BNPlatform* platform,
                                                       BNQualifiedName* name) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetPlatformFunctionByName(BNPlatform* platform,
                                                       BNQualifiedName* name,
                                                       bool exactMatch) {
  return {};
}
BINARYNINJACOREAPI char* BNGetPlatformSystemCallName(BNPlatform* platform,
                                                     uint32_t number) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetPlatformSystemCallType(BNPlatform* platform,
                                                       uint32_t number) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary** BNGetPlatformTypeLibraries(
    BNPlatform* platform, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeLibrary** BNGetPlatformTypeLibrariesByName(
    BNPlatform* platform, const char* depName, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDownloadProvider* BNRegisterDownloadProvider(
    const char* name, BNDownloadProviderCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNDownloadProvider** BNGetDownloadProviderList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDownloadProviderList(
    BNDownloadProvider** providers) {}
BINARYNINJACOREAPI BNDownloadProvider* BNGetDownloadProviderByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetDownloadProviderName(
    BNDownloadProvider* provider) {
  return {};
}
BINARYNINJACOREAPI BNDownloadInstance* BNCreateDownloadProviderInstance(
    BNDownloadProvider* provider) {
  return {};
}
BINARYNINJACOREAPI BNDownloadInstance* BNInitDownloadInstance(
    BNDownloadProvider* provider, BNDownloadInstanceCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNDownloadInstance* BNNewDownloadInstanceReference(
    BNDownloadInstance* instance) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDownloadInstance(BNDownloadInstance* instance) {}
BINARYNINJACOREAPI void BNFreeDownloadInstanceResponse(
    BNDownloadInstanceResponse* response) {}
BINARYNINJACOREAPI int BNPerformDownloadRequest(
    BNDownloadInstance* instance, const char* url,
    BNDownloadInstanceOutputCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI int BNPerformCustomRequest(
    BNDownloadInstance* instance, const char* method, const char* url,
    uint64_t headerCount, const char* const* headerKeys,
    const char* const* headerValues, BNDownloadInstanceResponse** response,
    BNDownloadInstanceInputOutputCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI int64_t BNReadDataForDownloadInstance(
    BNDownloadInstance* instance, uint8_t* data, uint64_t len) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNWriteDataForDownloadInstance(
    BNDownloadInstance* instance, uint8_t* data, uint64_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNNotifyProgressForDownloadInstance(
    BNDownloadInstance* instance, uint64_t progress, uint64_t total) {
  return {};
}
BINARYNINJACOREAPI char* BNGetErrorForDownloadInstance(
    BNDownloadInstance* instance) {
  return {};
}
BINARYNINJACOREAPI void BNSetErrorForDownloadInstance(
    BNDownloadInstance* instance, const char* error) {}
BINARYNINJACOREAPI BNWebsocketProvider* BNRegisterWebsocketProvider(
    const char* name, BNWebsocketProviderCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNWebsocketProvider** BNGetWebsocketProviderList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeWebsocketProviderList(
    BNWebsocketProvider** providers) {}
BINARYNINJACOREAPI BNWebsocketProvider* BNGetWebsocketProviderByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetWebsocketProviderName(
    BNWebsocketProvider* provider) {
  return {};
}
BINARYNINJACOREAPI BNWebsocketClient* BNCreateWebsocketProviderClient(
    BNWebsocketProvider* provider) {
  return {};
}
BINARYNINJACOREAPI BNWebsocketClient* BNInitWebsocketClient(
    BNWebsocketProvider* provider, BNWebsocketClientCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNWebsocketClient* BNNewWebsocketClientReference(
    BNWebsocketClient* client) {
  return {};
}
BINARYNINJACOREAPI void BNFreeWebsocketClient(BNWebsocketClient* client) {}
BINARYNINJACOREAPI bool BNConnectWebsocketClient(
    BNWebsocketClient* client, const char* url, uint64_t headerCount,
    const char* const* headerKeys, const char* const* headerValues,
    BNWebsocketClientOutputCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI bool BNNotifyWebsocketClientConnect(
    BNWebsocketClient* client) {
  return {};
}
BINARYNINJACOREAPI void BNNotifyWebsocketClientDisconnect(
    BNWebsocketClient* client) {}
BINARYNINJACOREAPI void BNNotifyWebsocketClientError(BNWebsocketClient* client,
                                                     const char* msg) {}
BINARYNINJACOREAPI bool BNNotifyWebsocketClientReadData(
    BNWebsocketClient* client, uint8_t* data, uint64_t len) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNWriteWebsocketClientData(
    BNWebsocketClient* client, const uint8_t* data, uint64_t len) {
  return {};
}
BINARYNINJACOREAPI bool BNDisconnectWebsocketClient(BNWebsocketClient* client) {
  return {};
}
BINARYNINJACOREAPI BNScriptingProvider* BNRegisterScriptingProvider(
    const char* name, const char* apiName,
    BNScriptingProviderCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNScriptingProvider** BNGetScriptingProviderList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeScriptingProviderList(
    BNScriptingProvider** providers) {}
BINARYNINJACOREAPI BNScriptingProvider* BNGetScriptingProviderByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNScriptingProvider* BNGetScriptingProviderByAPIName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetScriptingProviderName(
    BNScriptingProvider* provider) {
  return {};
}
BINARYNINJACOREAPI char* BNGetScriptingProviderAPIName(
    BNScriptingProvider* provider) {
  return {};
}
BINARYNINJACOREAPI BNScriptingInstance* BNCreateScriptingProviderInstance(
    BNScriptingProvider* provider) {
  return {};
}
BINARYNINJACOREAPI bool BNLoadScriptingProviderModule(
    BNScriptingProvider* provider, const char* repository, const char* module,
    bool force) {
  return {};
}
BINARYNINJACOREAPI bool BNInstallScriptingProviderModules(
    BNScriptingProvider* provider, const char* modules) {
  return {};
}
BINARYNINJACOREAPI bool BNIsScriptingProviderModuleInstalled(
    BNScriptingProvider* provider, const char* modules) {
  return {};
}
BINARYNINJACOREAPI void BNSetScriptingProviderModuleInstalledCallback(
    BNScriptingProvider* provider,
    BNScriptingProviderModuleInstalledCallbacks* callbacks) {}
BINARYNINJACOREAPI void
BNSetScriptingProviderInstallModulesWithExclusionsCallback(
    BNScriptingProvider* provider,
    BNScriptingProviderInstallModulesWithExclusionsCallbacks* callbacks) {}
BINARYNINJACOREAPI void BNSetScriptingProviderDependencyConflictCallback(
    BNScriptingProvider* provider,
    BNScriptingProviderDependencyConflictCallbacks* callbacks) {}
BINARYNINJACOREAPI void BNSetPluginDependencyStartupCallback(
    BNPluginDependencyStartupCallbacks* callbacks) {}
BINARYNINJACOREAPI void BNSetPluginDependencyResolutionCallback(
    BNPluginDependencyResolutionCallbacks* callbacks) {}
BINARYNINJACOREAPI BNScriptingInstance* BNInitScriptingInstance(
    BNScriptingProvider* provider, BNScriptingInstanceCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNScriptingInstance* BNNewScriptingInstanceReference(
    BNScriptingInstance* instance) {
  return {};
}
BINARYNINJACOREAPI void BNFreeScriptingInstance(BNScriptingInstance* instance) {
}
BINARYNINJACOREAPI void BNNotifyOutputForScriptingInstance(
    BNScriptingInstance* instance, const char* text) {}
BINARYNINJACOREAPI void BNNotifyWarningForScriptingInstance(
    BNScriptingInstance* instance, const char* text) {}
BINARYNINJACOREAPI void BNNotifyErrorForScriptingInstance(
    BNScriptingInstance* instance, const char* text) {}
BINARYNINJACOREAPI void BNNotifyInputReadyStateForScriptingInstance(
    BNScriptingInstance* instance, BNScriptingProviderInputReadyState state) {}
BINARYNINJACOREAPI void BNRegisterScriptingInstanceOutputListener(
    BNScriptingInstance* instance, BNScriptingOutputListener* callbacks) {}
BINARYNINJACOREAPI void BNUnregisterScriptingInstanceOutputListener(
    BNScriptingInstance* instance, BNScriptingOutputListener* callbacks) {}
BINARYNINJACOREAPI char* BNGetScriptingInstanceDelimiters(
    BNScriptingInstance* instance) {
  return {};
}
BINARYNINJACOREAPI void BNSetScriptingInstanceDelimiters(
    BNScriptingInstance* instance, const char* delimiters) {}
BINARYNINJACOREAPI BNScriptingProviderInputReadyState
BNGetScriptingInstanceInputReadyState(BNScriptingInstance* instance) {
  return {};
}
BINARYNINJACOREAPI BNScriptingProviderExecuteResult
BNExecuteScriptInput(BNScriptingInstance* instance, const char* input) {
  return {};
}
BINARYNINJACOREAPI BNScriptingProviderExecuteResult
BNExecuteScriptInputFromFilename(BNScriptingInstance* instance,
                                 const char* filename) {
  return {};
}
BINARYNINJACOREAPI void BNCancelScriptInput(BNScriptingInstance* instance) {}
BINARYNINJACOREAPI void BNScriptingInstanceReleaseBinaryView(
    BNScriptingInstance* instance, BNBinaryView* view) {}
BINARYNINJACOREAPI void BNSetScriptingInstanceCurrentBinaryView(
    BNScriptingInstance* instance, BNBinaryView* view) {}
BINARYNINJACOREAPI void BNSetScriptingInstanceCurrentFunction(
    BNScriptingInstance* instance, BNFunction* func) {}
BINARYNINJACOREAPI void BNSetScriptingInstanceCurrentBasicBlock(
    BNScriptingInstance* instance, BNBasicBlock* block) {}
BINARYNINJACOREAPI void BNSetScriptingInstanceCurrentAddress(
    BNScriptingInstance* instance, uint64_t addr) {}
BINARYNINJACOREAPI void BNSetScriptingInstanceCurrentSelection(
    BNScriptingInstance* instance, uint64_t begin, uint64_t end) {}
BINARYNINJACOREAPI char* BNScriptingInstanceCompleteInput(
    BNScriptingInstance* instance, const char* text, uint64_t state) {
  return {};
}
BINARYNINJACOREAPI bool BNScriptingInstanceCanCompleteArguments(
    BNScriptingInstance* instance, const char* text) {
  return {};
}
BINARYNINJACOREAPI char* BNScriptingInstanceCompleteArguments(
    BNScriptingInstance* instance, const char* text, uint64_t* argumentStart) {
  return {};
}
BINARYNINJACOREAPI void BNStopScriptingInstance(BNScriptingInstance* instance) {
}
BINARYNINJACOREAPI size_t BNFuzzyMatchSingle(const char* target,
                                             const char* query) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterMainThread(BNMainThreadCallbacks* callbacks) {
}
BINARYNINJACOREAPI BNMainThreadAction* BNNewMainThreadActionReference(
    BNMainThreadAction* action) {
  return {};
}
BINARYNINJACOREAPI void BNFreeMainThreadAction(BNMainThreadAction* action) {}
BINARYNINJACOREAPI void BNExecuteMainThreadAction(BNMainThreadAction* action) {}
BINARYNINJACOREAPI bool BNIsMainThreadActionDone(BNMainThreadAction* action) {
  return {};
}
BINARYNINJACOREAPI void BNWaitForMainThreadAction(BNMainThreadAction* action) {}
BINARYNINJACOREAPI BNMainThreadAction* BNExecuteOnMainThread(
    void* ctxt, void (*func)(void* ctxt)) {
  return {};
}
BINARYNINJACOREAPI void BNExecuteOnMainThreadAndWait(void* ctxt,
                                                     void (*func)(void* ctxt)) {
}
BINARYNINJACOREAPI bool BNIsMainThread(void) { return {}; }
BINARYNINJACOREAPI void BNWorkerEnqueue(void* ctxt,
                                        void (*action)(void* ctxt)) {}
BINARYNINJACOREAPI void BNWorkerEnqueueNamed(void* ctxt,
                                             void (*action)(void* ctxt),
                                             const char* name) {}
BINARYNINJACOREAPI void BNWorkerPriorityEnqueue(void* ctxt,
                                                void (*action)(void* ctxt)) {}
BINARYNINJACOREAPI void BNWorkerPriorityEnqueueNamed(void* ctxt,
                                                     void (*action)(void* ctxt),
                                                     const char* name) {}
BINARYNINJACOREAPI void BNWorkerInteractiveEnqueue(void* ctxt,
                                                   void (*action)(void* ctxt)) {
}
BINARYNINJACOREAPI void BNWorkerInteractiveEnqueueNamed(
    void* ctxt, void (*action)(void* ctxt), const char* name) {}
BINARYNINJACOREAPI size_t BNGetWorkerThreadCount(void) { return {}; }
BINARYNINJACOREAPI void BNSetWorkerThreadCount(size_t count) {}
BINARYNINJACOREAPI void BNSetThreadName(const char* name) {}
BINARYNINJACOREAPI BNBackgroundTask* BNBeginBackgroundTask(
    const char* initialText, bool canCancel) {
  return {};
}
BINARYNINJACOREAPI void BNFinishBackgroundTask(BNBackgroundTask* task) {}
BINARYNINJACOREAPI void BNSetBackgroundTaskProgressText(BNBackgroundTask* task,
                                                        const char* text) {}
BINARYNINJACOREAPI bool BNIsBackgroundTaskCancelled(BNBackgroundTask* task) {
  return {};
}
BINARYNINJACOREAPI BNBackgroundTask** BNGetRunningBackgroundTasks(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNBackgroundTask* BNNewBackgroundTaskReference(
    BNBackgroundTask* task) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBackgroundTask(BNBackgroundTask* task) {}
BINARYNINJACOREAPI void BNFreeBackgroundTaskList(BNBackgroundTask** tasks,
                                                 size_t count) {}
BINARYNINJACOREAPI char* BNGetBackgroundTaskProgressText(
    BNBackgroundTask* task) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNGetBackgroundTaskRuntimeSeconds(BNBackgroundTask* task) {
  return {};
}
BINARYNINJACOREAPI bool BNCanCancelBackgroundTask(BNBackgroundTask* task) {
  return {};
}
BINARYNINJACOREAPI void BNCancelBackgroundTask(BNBackgroundTask* task) {}
BINARYNINJACOREAPI bool BNIsBackgroundTaskFinished(BNBackgroundTask* task) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterInteractionHandler(
    BNInteractionHandlerCallbacks* callbacks) {}
BINARYNINJACOREAPI char* BNMarkdownToHTML(const char* contents) { return {}; }
BINARYNINJACOREAPI void BNShowPlainTextReport(BNBinaryView* view,
                                              const char* title,
                                              const char* contents) {}
BINARYNINJACOREAPI void BNShowMarkdownReport(BNBinaryView* view,
                                             const char* title,
                                             const char* contents,
                                             const char* plaintext) {}
BINARYNINJACOREAPI void BNShowHTMLReport(BNBinaryView* view, const char* title,
                                         const char* contents,
                                         const char* plaintext) {}
BINARYNINJACOREAPI void BNShowGraphReport(BNBinaryView* view, const char* title,
                                          BNFlowGraph* graph) {}
BINARYNINJACOREAPI void BNShowReportCollection(const char* title,
                                               BNReportCollection* reports) {}
BINARYNINJACOREAPI bool BNGetTextLineInput(char** result, const char* prompt,
                                           const char* title) {
  return {};
}
BINARYNINJACOREAPI bool BNGetIntegerInput(int64_t* result, const char* prompt,
                                          const char* title) {
  return {};
}
BINARYNINJACOREAPI bool BNGetAddressInput(uint64_t* result, const char* prompt,
                                          const char* title, BNBinaryView* view,
                                          uint64_t currentAddr) {
  return {};
}
BINARYNINJACOREAPI bool BNGetChoiceInput(size_t* result, const char* prompt,
                                         const char* title,
                                         const char** choices, size_t count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetLargeChoiceInput(size_t* result,
                                              const char* prompt,
                                              const char* title,
                                              const char** choices,
                                              size_t count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetOpenFileNameInput(char** result,
                                               const char* prompt,
                                               const char* ext) {
  return {};
}
BINARYNINJACOREAPI bool BNGetSaveFileNameInput(char** result,
                                               const char* prompt,
                                               const char* ext,
                                               const char* defaultName) {
  return {};
}
BINARYNINJACOREAPI bool BNGetDirectoryNameInput(char** result,
                                                const char* prompt,
                                                const char* defaultName) {
  return {};
}
BINARYNINJACOREAPI bool BNGetCheckboxInput(int64_t* result, const char* prompt,
                                           const char* title,
                                           const int64_t* defaultChoice) {
  return {};
}
BINARYNINJACOREAPI bool BNGetFormInput(BNFormInputField* fields, size_t count,
                                       const char* title) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFormInputResults(BNFormInputField* fields,
                                               size_t count) {}
BINARYNINJACOREAPI BNMessageBoxButtonResult
BNShowMessageBox(const char* title, const char* text,
                 BNMessageBoxButtonSet buttons, BNMessageBoxIcon icon) {
  return {};
}
BINARYNINJACOREAPI bool BNOpenUrl(const char* url) { return {}; }
BINARYNINJACOREAPI bool BNRunProgressDialog(
    const char* title, bool canCancel,
    void (*task)(void* taskCtxt, BNProgressFunction progress,
                 void* progressCtxt),
    void* taskCtxt) {
  return {};
}
BINARYNINJACOREAPI BNReportCollection* BNCreateReportCollection(void) {
  return {};
}
BINARYNINJACOREAPI BNReportCollection* BNNewReportCollectionReference(
    BNReportCollection* reports) {
  return {};
}
BINARYNINJACOREAPI void BNFreeReportCollection(BNReportCollection* reports) {}
BINARYNINJACOREAPI size_t
BNGetReportCollectionCount(BNReportCollection* reports) {
  return {};
}
BINARYNINJACOREAPI BNReportType BNGetReportType(BNReportCollection* reports,
                                                size_t i) {
  return {};
}
BINARYNINJACOREAPI BNBinaryView* BNGetReportView(BNReportCollection* reports,
                                                 size_t i) {
  return {};
}
BINARYNINJACOREAPI char* BNGetReportTitle(BNReportCollection* reports,
                                          size_t i) {
  return {};
}
BINARYNINJACOREAPI char* BNGetReportContents(BNReportCollection* reports,
                                             size_t i) {
  return {};
}
BINARYNINJACOREAPI char* BNGetReportPlainText(BNReportCollection* reports,
                                              size_t i) {
  return {};
}
BINARYNINJACOREAPI BNFlowGraph* BNGetReportFlowGraph(
    BNReportCollection* reports, size_t i) {
  return {};
}
BINARYNINJACOREAPI void BNAddPlainTextReportToCollection(
    BNReportCollection* reports, BNBinaryView* view, const char* title,
    const char* contents) {}
BINARYNINJACOREAPI void BNAddMarkdownReportToCollection(
    BNReportCollection* reports, BNBinaryView* view, const char* title,
    const char* contents, const char* plaintext) {}
BINARYNINJACOREAPI void BNAddHTMLReportToCollection(BNReportCollection* reports,
                                                    BNBinaryView* view,
                                                    const char* title,
                                                    const char* contents,
                                                    const char* plaintext) {}
BINARYNINJACOREAPI void BNAddGraphReportToCollection(
    BNReportCollection* reports, BNBinaryView* view, const char* title,
    BNFlowGraph* graph) {}
BINARYNINJACOREAPI void BNUpdateReportFlowGraph(BNReportCollection* reports,
                                                size_t i, BNFlowGraph* graph) {}
BINARYNINJACOREAPI BNDemanglerConfig BNGetDefaultDemanglerConfig(void) {
  return {};
}
BINARYNINJACOREAPI BNDemanglerConfig
BNGetDemanglerConfigForPlatform(BNPlatform* platform, bool simplifyTemplates) {
  return {};
}
BINARYNINJACOREAPI BNDemanglerConfig
BNGetDemanglerConfigForBinaryView(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI bool BNDemangle(const char* name,
                                   const BNDemanglerConfig* config,
                                   BNDemanglerResult* result) {
  return {};
}
BINARYNINJACOREAPI bool BNDemangleWithDemangler(const BNDemangler* demangler,
                                                const char* name,
                                                const BNDemanglerConfig* config,
                                                BNDemanglerResult* result) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDemanglerResult(BNDemanglerResult* result) {}
BINARYNINJACOREAPI bool BNSimplifyDemangledTemplateName(
    const BNQualifiedName* name, BNQualifiedName* result) {
  return {};
}
BINARYNINJACOREAPI BNDemangler* BNRegisterDemangler(
    const char* name, const BNDemanglerCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNDemangler** BNGetDemanglerList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDemanglerList(BNDemangler** demanglers) {}
BINARYNINJACOREAPI BNDemangler* BNGetDemanglerByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNDemangler* BNGetMSVCDemangler(void) { return {}; }
BINARYNINJACOREAPI BNDemangler* BNGetGNU3Demangler(void) { return {}; }
BINARYNINJACOREAPI BNDemangler* BNGetLLVMDemangler(void) { return {}; }
BINARYNINJACOREAPI char* BNGetDemanglerName(const BNDemangler* demangler) {
  return {};
}
BINARYNINJACOREAPI bool BNPromoteDemangler(const BNDemangler* demangler) {
  return {};
}
BINARYNINJACOREAPI bool BNIsDemanglerMangledName(const BNDemangler* demangler,
                                                 const char* name) {
  return {};
}
BINARYNINJACOREAPI char** BNPluginGetApis(BNPlugin* p, size_t* count) {
  return {};
}
BINARYNINJACOREAPI const char* BNPluginGetAuthor(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const char* BNPluginGetDescription(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI const char* BNPluginGetLicenseText(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI BNVersionInfo BNPluginGetMinimumVersionInfo(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI BNVersionInfo BNPluginGetMaximumVersionInfo(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI BNVersionInfo BNParseVersionString(const char* v) {
  return {};
}
BINARYNINJACOREAPI bool BNVersionLessThan(const BNVersionInfo smaller,
                                          const BNVersionInfo larger) {
  return {};
}
BINARYNINJACOREAPI bool BNPluginVersionIDLessThan(BNPlugin* p,
                                                  const char* smaller,
                                                  const char* larger) {
  return {};
}
BINARYNINJACOREAPI const char* BNPluginGetName(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const char* BNPluginGetProjectUrl(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const char* BNPluginGetPackageUrl(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const char* BNPluginGetAuthorUrl(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI BNPluginVersion* BNPluginGetVersions(BNPlugin* p,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePluginVersions(BNPluginVersion* r, size_t count) {
}
BINARYNINJACOREAPI const char* BNPluginGetCurrentVersionID(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI const char* BNPluginGetLatestVersionID(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI BNPluginVersion BNPluginGetCurrentVersion(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI void BNPluginFreeVersion(BNPluginVersion v) {}
BINARYNINJACOREAPI const char* BNPluginGetCommit(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const bool BNPluginGetViewOnly(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const bool BNPluginGetIsPaid(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI void BNFreePluginTypes(BNPluginType* r) {}
BINARYNINJACOREAPI BNPlugin* BNNewPluginReference(BNPlugin* r) { return {}; }
BINARYNINJACOREAPI void BNFreePlugin(BNPlugin* plugin) {}
BINARYNINJACOREAPI const char* BNPluginGetPath(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const char* BNPluginGetSubdir(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI const char* BNPluginGetDependencies(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI const char* BNPluginGetDependenciesForVersion(
    BNPlugin* p, const char* versionID) {
  return {};
}
BINARYNINJACOREAPI BNPluginDependencyConflict* BNPluginGetDependencyConflicts(
    BNPlugin* p, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNPluginDependencyConflict*
BNPluginGetDependencyConflictsForVersion(BNPlugin* p, const char* versionID,
                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePluginDependencyConflicts(
    BNPluginDependencyConflict* conflicts, size_t count) {}
BINARYNINJACOREAPI const char* BNPluginGetLongdescription(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNPluginGetLastUpdate(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsInstalled(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsListed(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsDeprecated(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsEnabled(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI BNPluginStatus BNPluginGetPluginStatus(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI BNPluginType* BNPluginGetPluginTypes(BNPlugin* p,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNPluginEnable(BNPlugin* p, bool force) { return {}; }
BINARYNINJACOREAPI bool BNPluginDisable(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginInstall(BNPlugin* p, const char* versionID) {
  return {};
}
BINARYNINJACOREAPI bool BNPluginInstallDependencies(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginInstallDependenciesForVersion(
    BNPlugin* p, const char* versionID) {
  return {};
}
BINARYNINJACOREAPI bool BNPluginInstallDependenciesWithExclusions(
    BNPlugin* p, const char* const* excludedPackageNames,
    size_t excludedPackageNameCount) {
  return {};
}
BINARYNINJACOREAPI bool BNPluginInstallDependenciesWithExclusionsForVersion(
    BNPlugin* p, const char* versionID, const char* const* excludedPackageNames,
    size_t excludedPackageNameCount) {
  return {};
}
BINARYNINJACOREAPI bool BNPluginUninstall(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginCancelUninstall(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginUpdate(BNPlugin* p, const char* versionID) {
  return {};
}
BINARYNINJACOREAPI char** BNPluginGetPlatforms(BNPlugin* p, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreePluginPlatforms(char** platforms, size_t count) {}
BINARYNINJACOREAPI const char* BNPluginGetRepository(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsBeingDeleted(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsBeingUpdated(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsRunning(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsUpdatePending(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsDisablePending(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsDeletePending(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginIsUpdateAvailable(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI bool BNPluginAreDependenciesBeingInstalled(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI char* BNPluginGetProjectData(BNPlugin* p) { return {}; }
BINARYNINJACOREAPI char* BNPluginGetCurrentVersionCreationDate(BNPlugin* p) {
  return {};
}
BINARYNINJACOREAPI BNRepository* BNNewRepositoryReference(BNRepository* r) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRepository(BNRepository* r) {}
BINARYNINJACOREAPI char* BNRepositoryGetUrl(BNRepository* r) { return {}; }
BINARYNINJACOREAPI char* BNRepositoryGetRepoPath(BNRepository* r) { return {}; }
BINARYNINJACOREAPI BNPlugin** BNRepositoryGetPlugins(BNRepository* r,
                                                     size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRepositoryPluginList(BNPlugin** r) {}
BINARYNINJACOREAPI void BNRepositoryFreePluginDirectoryList(char** list,
                                                            size_t count) {}
BINARYNINJACOREAPI BNPlugin* BNRepositoryGetPluginByPath(
    BNRepository* r, const char* pluginPath) {
  return {};
}
BINARYNINJACOREAPI const char* BNRepositoryGetPluginsPath(BNRepository* r) {
  return {};
}
BINARYNINJACOREAPI bool BNRepositoryManagerCheckForUpdates() { return {}; }
BINARYNINJACOREAPI BNRepository** BNRepositoryManagerGetRepositories(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRepositoryManagerRepositoriesList(
    BNRepository** r) {}
BINARYNINJACOREAPI bool BNRepositoryManagerAddRepository(const char* url,
                                                         const char* repoPath) {
  return {};
}
BINARYNINJACOREAPI BNRepository* BNRepositoryGetRepositoryByPath(
    const char* repoPath) {
  return {};
}
BINARYNINJACOREAPI BNRepository* BNRepositoryManagerGetDefaultRepository() {
  return {};
}
BINARYNINJACOREAPI BNComponent* BNNewComponentReference(
    BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI void BNFreeComponent(BNComponent* component) {}
BINARYNINJACOREAPI BNFunction** BNComponentGetContainedFunctions(
    BNComponent* component, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNComponent** BNComponentGetContainedComponents(
    BNComponent* component, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDataVariable* BNComponentGetContainedDataVariables(
    BNComponent* component, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDataVariable* BNComponentGetReferencedDataVariables(
    BNComponent* component, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDataVariable*
BNComponentGetReferencedDataVariablesRecursive(BNComponent* component,
                                               size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType** BNComponentGetReferencedTypes(
    BNComponent* component, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType** BNComponentGetReferencedTypesRecursive(
    BNComponent* component, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeComponents(BNComponent** components,
                                         size_t count) {}
BINARYNINJACOREAPI void BNComponentFreeReferencedTypes(BNType** types,
                                                       size_t count) {}
BINARYNINJACOREAPI BNComponent* BNComponentGetParent(BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentContainsFunction(BNComponent* component,
                                                    BNFunction* function) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentContainsComponent(BNComponent* parent,
                                                     BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentContainsDataVariable(BNComponent* component,
                                                        uint64_t address) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentAddFunctionReference(BNComponent* component,
                                                        BNFunction* function) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentAddComponent(BNComponent* parent,
                                                BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentAddDataVariable(BNComponent* component,
                                                   uint64_t address) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentRemoveComponent(BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentRemoveFunctionReference(
    BNComponent* component, BNFunction* function) {
  return {};
}
BINARYNINJACOREAPI void BNComponentRemoveAllFunctions(BNComponent* component) {}
BINARYNINJACOREAPI bool BNComponentRemoveDataVariable(BNComponent* component,
                                                      uint64_t address) {
  return {};
}
BINARYNINJACOREAPI void BNComponentAddAllMembersFromComponent(
    BNComponent* component, BNComponent* fromComponent) {}
BINARYNINJACOREAPI char* BNComponentGetGuid(BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentsEqual(BNComponent* a, BNComponent* b) {
  return {};
}
BINARYNINJACOREAPI bool BNComponentsNotEqual(BNComponent* a, BNComponent* b) {
  return {};
}
BINARYNINJACOREAPI char* BNComponentGetDisplayName(BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI char* BNComponentGetOriginalName(BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI void BNComponentSetName(BNComponent* component,
                                           const char* name) {}
BINARYNINJACOREAPI BNBinaryView* BNComponentGetView(BNComponent* component) {
  return {};
}
BINARYNINJACOREAPI void BNLlvmServicesInit(void) {}
BINARYNINJACOREAPI int BNLlvmServicesAssemble(const char* src, int dialect,
                                              const char* triplet,
                                              int codeModel, int relocMode,
                                              char** outBytes, int* outBytesLen,
                                              char** err, int* errLen) {
  return {};
}
BINARYNINJACOREAPI void BNLlvmServicesAssembleFree(char* outBytes, char* err) {}
BINARYNINJACOREAPI int BNLlvmServicesDisasmInstruction(const char* triplet,
                                                       uint8_t* src, int srcLen,
                                                       uint64_t addr,
                                                       char* result,
                                                       size_t resultMaxSize) {
  return {};
}
BINARYNINJACOREAPI bool BNDeleteFile(const char* path) { return {}; }
BINARYNINJACOREAPI bool BNDeleteDirectory(const char* path) { return {}; }
BINARYNINJACOREAPI bool BNCreateDirectory(const char* path,
                                          bool createSubdirectories) {
  return {};
}
BINARYNINJACOREAPI bool BNPathExists(const char* path) { return {}; }
BINARYNINJACOREAPI bool BNIsPathDirectory(const char* path) { return {}; }
BINARYNINJACOREAPI bool BNIsPathRegularFile(const char* path) { return {}; }
BINARYNINJACOREAPI bool BNFileSize(const char* path, uint64_t* size) {
  return {};
}
BINARYNINJACOREAPI bool BNRenameFile(const char* source, const char* dest) {
  return {};
}
BINARYNINJACOREAPI bool BNCopyFile(const char* source, const char* dest) {
  return {};
}
BINARYNINJACOREAPI char** BNGetFilePathsInDirectory(const char* path,
                                                    size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSystemCacheDirectory() { return {}; }
BINARYNINJACOREAPI BNSettings* BNCreateSettings(const char* schemaId) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNNewSettingsReference(BNSettings* settings) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSettings(BNSettings* settings) {}
BINARYNINJACOREAPI bool BNLoadSettingsFile(BNSettings* settings,
                                           const char* fileName,
                                           BNSettingsScope scope,
                                           BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNSettingsSetResourceId(BNSettings* settings,
                                                const char* resourceId) {}
BINARYNINJACOREAPI bool BNSettingsRegisterGroup(BNSettings* settings,
                                                const char* group,
                                                const char* title) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsRegisterSetting(BNSettings* settings,
                                                  const char* key,
                                                  const char* properties) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsContains(BNSettings* settings,
                                           const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsIsEmpty(BNSettings* settings,
                                          BNBinaryView* view, BNFunction* func,
                                          BNSettingsScope scope) {
  return {};
}
BINARYNINJACOREAPI const char** BNSettingsKeysList(BNSettings* settings,
                                                   size_t* inoutSize) {
  return {};
}
BINARYNINJACOREAPI char* BNSettingsQueryPropertyString(BNSettings* settings,
                                                       const char* key,
                                                       const char* property) {
  return {};
}
BINARYNINJACOREAPI const char** BNSettingsQueryPropertyStringList(
    BNSettings* settings, const char* key, const char* property,
    size_t* inoutSize) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateProperty(BNSettings* settings,
                                                 const char* key,
                                                 const char* property) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateBoolProperty(BNSettings* settings,
                                                     const char* key,
                                                     const char* property,
                                                     bool value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateDoubleProperty(BNSettings* settings,
                                                       const char* key,
                                                       const char* property,
                                                       double value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateInt64Property(BNSettings* settings,
                                                      const char* key,
                                                      const char* property,
                                                      int64_t value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateUInt64Property(BNSettings* settings,
                                                       const char* key,
                                                       const char* property,
                                                       uint64_t value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateStringProperty(BNSettings* settings,
                                                       const char* key,
                                                       const char* property,
                                                       const char* value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsUpdateStringListProperty(BNSettings* settings,
                                                           const char* key,
                                                           const char* property,
                                                           const char** value,
                                                           size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsDeserializeSchema(BNSettings* settings,
                                                    const char* schema,
                                                    BNSettingsScope scope,
                                                    bool merge) {
  return {};
}
BINARYNINJACOREAPI char* BNSettingsSerializeSchema(BNSettings* settings) {
  return {};
}
BINARYNINJACOREAPI bool BNDeserializeSettings(BNSettings* settings,
                                              const char* contents,
                                              BNBinaryView* view,
                                              BNFunction* func,
                                              BNSettingsScope scope) {
  return {};
}
BINARYNINJACOREAPI char* BNSerializeSettings(BNSettings* settings,
                                             BNBinaryView* view,
                                             BNFunction* func,
                                             BNSettingsScope scope) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsReset(BNSettings* settings, const char* key,
                                        BNBinaryView* view, BNFunction* func,
                                        BNSettingsScope scope) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsResetAll(BNSettings* settings,
                                           BNBinaryView* view, BNFunction* func,
                                           BNSettingsScope scope,
                                           bool schemaOnly) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsGetBool(BNSettings* settings, const char* key,
                                          BNBinaryView* view, BNFunction* func,
                                          BNSettingsScope* scope) {
  return {};
}
BINARYNINJACOREAPI double BNSettingsGetDouble(BNSettings* settings,
                                              const char* key,
                                              BNBinaryView* view,
                                              BNFunction* func,
                                              BNSettingsScope* scope) {
  return {};
}
BINARYNINJACOREAPI int64_t BNSettingsGetInt64(BNSettings* settings,
                                              const char* key,
                                              BNBinaryView* view,
                                              BNFunction* func,
                                              BNSettingsScope* scope) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSettingsGetUInt64(BNSettings* settings,
                                                const char* key,
                                                BNBinaryView* view,
                                                BNFunction* func,
                                                BNSettingsScope* scope) {
  return {};
}
BINARYNINJACOREAPI char* BNSettingsGetString(BNSettings* settings,
                                             const char* key,
                                             BNBinaryView* view,
                                             BNFunction* func,
                                             BNSettingsScope* scope) {
  return {};
}
BINARYNINJACOREAPI const char** BNSettingsGetStringList(
    BNSettings* settings, const char* key, BNBinaryView* view, BNFunction* func,
    BNSettingsScope* scope, size_t* inoutSize) {
  return {};
}
BINARYNINJACOREAPI char* BNSettingsGetJson(BNSettings* settings,
                                           const char* key, BNBinaryView* view,
                                           BNFunction* func,
                                           BNSettingsScope* scope) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetBool(BNSettings* settings,
                                          BNBinaryView* view, BNFunction* func,
                                          BNSettingsScope scope,
                                          const char* key, bool value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetDouble(BNSettings* settings,
                                            BNBinaryView* view,
                                            BNFunction* func,
                                            BNSettingsScope scope,
                                            const char* key, double value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetInt64(BNSettings* settings,
                                           BNBinaryView* view, BNFunction* func,
                                           BNSettingsScope scope,
                                           const char* key, int64_t value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetUInt64(BNSettings* settings,
                                            BNBinaryView* view,
                                            BNFunction* func,
                                            BNSettingsScope scope,
                                            const char* key, uint64_t value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetString(
    BNSettings* settings, BNBinaryView* view, BNFunction* func,
    BNSettingsScope scope, const char* key, const char* value) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetStringList(
    BNSettings* settings, BNBinaryView* view, BNFunction* func,
    BNSettingsScope scope, const char* key, const char** value, size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNSettingsSetJson(BNSettings* settings,
                                          BNBinaryView* view, BNFunction* func,
                                          BNSettingsScope scope,
                                          const char* key, const char* value) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNNewMetadataReference(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataBooleanData(bool data) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataStringData(const char* data) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataUnsignedIntegerData(
    uint64_t data) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataSignedIntegerData(int64_t data) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataDoubleData(double data) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataOfType(BNMetadataType type) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataRawData(const uint8_t* data,
                                                       size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataArray(BNMetadata** data,
                                                     size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataValueStore(const char** keys,
                                                          BNMetadata** values,
                                                          size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataBooleanListData(bool* data,
                                                               size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataUnsignedIntegerListData(
    uint64_t* data, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataSignedIntegerListData(
    int64_t* data, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataDoubleListData(double* data,
                                                              size_t size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNCreateMetadataStringListData(const char** data,
                                                              size_t size) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataIsEqual(BNMetadata* lhs, BNMetadata* rhs) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataSetValueForKey(BNMetadata* data,
                                                 const char* key,
                                                 BNMetadata* md) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNMetadataGetForKey(BNMetadata* data,
                                                   const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataArrayAppend(BNMetadata* data,
                                              BNMetadata* md) {
  return {};
}
BINARYNINJACOREAPI void BNMetadataRemoveKey(BNMetadata* data, const char* key) {
}
BINARYNINJACOREAPI size_t BNMetadataSize(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI BNMetadata* BNMetadataGetForIndex(BNMetadata* data,
                                                     size_t index) {
  return {};
}
BINARYNINJACOREAPI void BNMetadataRemoveIndex(BNMetadata* data, size_t index) {}
BINARYNINJACOREAPI void BNFreeMetadataArray(BNMetadata** data) {}
BINARYNINJACOREAPI void BNFreeMetadataValueStore(BNMetadataValueStore* data) {}
BINARYNINJACOREAPI void BNFreeMetadata(BNMetadata* data) {}
BINARYNINJACOREAPI void BNFreeMetadataRaw(uint8_t* data) {}
BINARYNINJACOREAPI void BNFreeMetadataBooleanList(bool*, size_t) {}
BINARYNINJACOREAPI void BNFreeMetadataUnsignedIntegerList(uint64_t*, size_t) {}
BINARYNINJACOREAPI void BNFreeMetadataSignedIntegerList(int64_t*, size_t) {}
BINARYNINJACOREAPI void BNFreeMetadataDoubleList(double*, size_t) {}
BINARYNINJACOREAPI void BNFreeMetadataStringList(char**, size_t) {}
BINARYNINJACOREAPI bool BNMetadataGetBoolean(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI char* BNMetadataGetString(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI uint64_t BNMetadataGetUnsignedInteger(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI int64_t BNMetadataGetSignedInteger(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI double BNMetadataGetDouble(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool* BNMetadataGetBooleanList(BNMetadata* data, size_t*) {
  return {};
}
BINARYNINJACOREAPI char** BNMetadataGetStringList(BNMetadata* data, size_t*) {
  return {};
}
BINARYNINJACOREAPI uint64_t* BNMetadataGetUnsignedIntegerList(BNMetadata* data,
                                                              size_t*) {
  return {};
}
BINARYNINJACOREAPI int64_t* BNMetadataGetSignedIntegerList(BNMetadata* data,
                                                           size_t*) {
  return {};
}
BINARYNINJACOREAPI double* BNMetadataGetDoubleList(BNMetadata* data, size_t*) {
  return {};
}
BINARYNINJACOREAPI uint8_t* BNMetadataGetRaw(BNMetadata* data, size_t* size) {
  return {};
}
BINARYNINJACOREAPI BNMetadata** BNMetadataGetArray(BNMetadata* data,
                                                   size_t* size) {
  return {};
}
BINARYNINJACOREAPI BNMetadataValueStore* BNMetadataGetValueStore(
    BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI char* BNMetadataGetJsonString(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI BNMetadataType BNMetadataGetType(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataIsBoolean(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsString(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsUnsignedInteger(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataIsSignedInteger(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataIsDouble(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsBooleanList(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsStringList(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsUnsignedIntegerList(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataIsSignedIntegerList(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI bool BNMetadataIsDoubleList(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsRaw(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsArray(BNMetadata* data) { return {}; }
BINARYNINJACOREAPI bool BNMetadataIsKeyValueStore(BNMetadata* data) {
  return {};
}
BINARYNINJACOREAPI void BNBinaryViewStoreMetadata(BNBinaryView* view,
                                                  const char* key,
                                                  BNMetadata* value,
                                                  BNMetadataStoreFlag flags) {}
BINARYNINJACOREAPI BNMetadata* BNBinaryViewQueryMetadata(BNBinaryView* view,
                                                         const char* key) {
  return {};
}
BINARYNINJACOREAPI void BNBinaryViewRemoveMetadata(BNBinaryView* view,
                                                   const char* key) {}
BINARYNINJACOREAPI BNMetadata* BNBinaryViewGetMetadata(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNBinaryViewGetAutoMetadata(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI char** BNBinaryViewGetLoadSettingsTypeNames(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNSettings* BNBinaryViewGetLoadSettings(
    BNBinaryView* view, const char* typeName) {
  return {};
}
BINARYNINJACOREAPI void BNBinaryViewSetLoadSettings(BNBinaryView* view,
                                                    const char* typeName,
                                                    BNSettings* settings) {}
BINARYNINJACOREAPI bool BNBinaryViewFinalizeNewSegments(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNRelocation* BNNewRelocationReference(BNRelocation* reloc) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRelocation(BNRelocation* reloc) {}
BINARYNINJACOREAPI BNRelocationInfo BNRelocationGetInfo(BNRelocation* reloc) {
  return {};
}
BINARYNINJACOREAPI BNArchitecture* BNRelocationGetArchitecture(
    BNRelocation* reloc) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNRelocationGetTarget(BNRelocation* reloc) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNRelocationGetReloc(BNRelocation* reloc) {
  return {};
}
BINARYNINJACOREAPI BNSymbol* BNRelocationGetSymbol(BNRelocation* reloc) {
  return {};
}
BINARYNINJACOREAPI BNSegment* BNCreateSegment(uint64_t start, uint64_t length,
                                              uint64_t dataOffset,
                                              uint64_t dataLength,
                                              uint32_t flags,
                                              bool autoDefined) {
  return {};
}
BINARYNINJACOREAPI BNSegment* BNNewSegmentReference(BNSegment* seg) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSegment(BNSegment* seg) {}
BINARYNINJACOREAPI uint64_t BNSegmentGetStart(BNSegment* segment) { return {}; }
BINARYNINJACOREAPI uint64_t BNSegmentGetLength(BNSegment* segment) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSegmentGetEnd(BNSegment* segment) { return {}; }
BINARYNINJACOREAPI uint64_t BNSegmentGetDataEnd(BNSegment* segment) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSegmentGetDataOffset(BNSegment* segment) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSegmentGetDataLength(BNSegment* segment) {
  return {};
}
BINARYNINJACOREAPI uint32_t BNSegmentGetFlags(BNSegment* segment) { return {}; }
BINARYNINJACOREAPI bool BNSegmentIsAutoDefined(BNSegment* segment) {
  return {};
}
BINARYNINJACOREAPI BNSection* BNNewSectionReference(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSection(BNSection* section) {}
BINARYNINJACOREAPI char* BNSectionGetName(BNSection* section) { return {}; }
BINARYNINJACOREAPI char* BNSectionGetType(BNSection* section) { return {}; }
BINARYNINJACOREAPI uint64_t BNSectionGetStart(BNSection* section) { return {}; }
BINARYNINJACOREAPI uint64_t BNSectionGetLength(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSectionGetEnd(BNSection* section) { return {}; }
BINARYNINJACOREAPI char* BNSectionGetLinkedSection(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI char* BNSectionGetInfoSection(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSectionGetInfoData(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNSectionGetAlign(BNSection* section) { return {}; }
BINARYNINJACOREAPI uint64_t BNSectionGetEntrySize(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI BNSectionSemantics
BNSectionGetSemantics(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI bool BNSectionIsAutoDefined(BNSection* section) {
  return {};
}
BINARYNINJACOREAPI BNDataRenderer* BNCreateDataRenderer(
    BNCustomDataRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNDataRenderer* BNNewDataRendererReference(
    BNDataRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI bool BNIsValidForData(void* ctxt, BNBinaryView* view,
                                         uint64_t addr, BNType* type,
                                         BNTypeContext* typeCtx,
                                         size_t ctxCount) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNGetLinesForData(
    void* ctxt, BNBinaryView* view, uint64_t addr, BNType* type,
    const BNInstructionTextToken* prefix, size_t prefixCount, size_t width,
    size_t* count, BNTypeContext* typeCtx, size_t ctxCount,
    const char* language) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNRenderLinesForData(
    BNBinaryView* data, uint64_t addr, BNType* type,
    const BNInstructionTextToken* prefix, size_t prefixCount, size_t width,
    size_t* count, BNTypeContext* typeCtx, size_t ctxCount,
    const char* language) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDataRenderer(BNDataRenderer* renderer) {}
BINARYNINJACOREAPI BNDataRendererContainer* BNGetDataRendererContainer(void) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterGenericDataRenderer(
    BNDataRendererContainer* container, BNDataRenderer* renderer) {}
BINARYNINJACOREAPI void BNRegisterTypeSpecificDataRenderer(
    BNDataRendererContainer* container, BNDataRenderer* renderer) {}
BINARYNINJACOREAPI bool BNParseExpression(BNBinaryView* view,
                                          const char* expression,
                                          uint64_t* offset, uint64_t here,
                                          char** errorString) {
  return {};
}
BINARYNINJACOREAPI void BNFreeParseError(char* errorString) {}
BINARYNINJACOREAPI char* BNGetCurrentStackTraceString(void) { return {}; }
BINARYNINJACOREAPI void* BNRegisterObjectRefDebugTrace(const char* typeName) {
  return {};
}
BINARYNINJACOREAPI void BNUnregisterObjectRefDebugTrace(const char* typeName,
                                                        void* trace) {}
BINARYNINJACOREAPI BNMemoryUsageInfo* BNGetMemoryUsageInfo(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeMemoryUsageInfo(BNMemoryUsageInfo* info,
                                              size_t count) {}
BINARYNINJACOREAPI BNStatHistogram* BNGetStatHistograms(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStatHistograms(BNStatHistogram* stats,
                                             size_t count) {}
BINARYNINJACOREAPI uint32_t BNGetAddressRenderedWidth(uint64_t addr) {
  return {};
}
BINARYNINJACOREAPI BNDebugInfoParser* BNRegisterDebugInfoParser(
    const char* name, bool (*isValid)(void*, BNBinaryView*),
    bool (*parseInfo)(void*, BNDebugInfo*, BNBinaryView*, BNBinaryView*,
                      BNProgressFunction, void*),
    void* context) {
  return {};
}
BINARYNINJACOREAPI void BNUnregisterDebugInfoParser(const char* rawName) {}
BINARYNINJACOREAPI BNDebugInfoParser* BNGetDebugInfoParserByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNDebugInfoParser** BNGetDebugInfoParsers(size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDebugInfoParser** BNGetDebugInfoParsersForView(
    BNBinaryView* view, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNGetDebugInfoParserName(BNDebugInfoParser* parser) {
  return {};
}
BINARYNINJACOREAPI bool BNIsDebugInfoParserValidForView(
    BNDebugInfoParser* parser, BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI BNDebugInfo* BNParseDebugInfo(BNDebugInfoParser* parser,
                                                 BNBinaryView* view,
                                                 BNBinaryView* debugFile,
                                                 BNDebugInfo* existingDebugInfo,
                                                 BNProgressFunction progress,
                                                 void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI BNDebugInfoParser* BNNewDebugInfoParserReference(
    BNDebugInfoParser* parser) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDebugInfoParserReference(
    BNDebugInfoParser* parser) {}
BINARYNINJACOREAPI void BNFreeDebugInfoParserList(BNDebugInfoParser** parsers,
                                                  size_t count) {}
BINARYNINJACOREAPI BNDebugInfo* BNNewDebugInfoReference(
    BNDebugInfo* debugInfo) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDebugInfoReference(BNDebugInfo* debugInfo) {}
BINARYNINJACOREAPI char** BNGetDebugParserNames(BNDebugInfo* const debugInfo,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainer* BNGetDebugInfoTypeContainer(
    BNDebugInfo* debugInfo, const char* const parserName) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugParserInfo(BNDebugInfo* const debugInfo,
                                                const char* const parserName) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugParserTypes(BNDebugInfo* const debugInfo,
                                                 const char* const parserName) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugParserFunctions(
    BNDebugInfo* const debugInfo, const char* const parserName) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugParserDataVariables(
    BNDebugInfo* const debugInfo, const char* const parserName) {
  return {};
}
BINARYNINJACOREAPI bool BNAddDebugType(BNDebugInfo* const debugInfo,
                                       const char* const name,
                                       const BNType* const type,
                                       const char** const components,
                                       size_t components_count) {
  return {};
}
BINARYNINJACOREAPI BNNameAndType* BNGetDebugTypes(BNDebugInfo* const debugInfo,
                                                  const char* const name,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetDebugTypeByName(BNDebugInfo* const debugInfo,
                                                const char* const parserName,
                                                const char* const typeName) {
  return {};
}
BINARYNINJACOREAPI BNNameAndType* BNGetDebugTypesByName(
    BNDebugInfo* const debugInfo, const char* const typeName, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugTypeByName(BNDebugInfo* const debugInfo,
                                                const char* const parserName,
                                                const char* typeName) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDebugTypes(BNNameAndType* types, size_t count) {}
BINARYNINJACOREAPI bool BNAddDebugFunction(BNDebugInfo* const debugInfo,
                                           BNDebugFunctionInfo* func) {
  return {};
}
BINARYNINJACOREAPI BNDebugFunctionInfo* BNGetDebugFunctions(
    BNDebugInfo* const debugInfo, const char* const name, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugFunctionByIndex(
    BNDebugInfo* const debugInfo, const char* const parserName,
    const size_t index) {
  return {};
}
BINARYNINJACOREAPI void BNFreeDebugFunctions(BNDebugFunctionInfo* functions,
                                             size_t count) {}
BINARYNINJACOREAPI bool BNAddDebugDataVariable(
    BNDebugInfo* const debugInfo, uint64_t address, const BNType* const type,
    const char* name, const char** const components, size_t components_count) {
  return {};
}
BINARYNINJACOREAPI bool BNAddDebugDataVariableInfo(
    BNDebugInfo* const debugInfo, const BNDataVariableAndName* var) {
  return {};
}
BINARYNINJACOREAPI BNDataVariableAndName* BNGetDebugDataVariables(
    BNDebugInfo* const debugInfo, const char* const name, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetDebugDataVariableByName(
    BNDebugInfo* const debugInfo, const char* const parserName,
    const char* const variableName, BNDataVariableAndName* var) {
  return {};
}
BINARYNINJACOREAPI bool BNGetDebugDataVariableByAddress(
    BNDebugInfo* const debugInfo, const char* const parserName,
    const uint64_t address, BNDataVariableAndName* var) {
  return {};
}
BINARYNINJACOREAPI BNDataVariableAndName* BNGetDebugDataVariablesByName(
    BNDebugInfo* const debugInfo, const char* const variableName,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNDataVariableAndNameAndDebugParser*
BNGetDebugDataVariablesByAddress(BNDebugInfo* const debugInfo,
                                 const uint64_t address, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoveDebugDataVariableByAddress(
    BNDebugInfo* const debugInfo, const char* const parserName,
    const uint64_t address) {
  return {};
}
BINARYNINJACOREAPI BNSecretsProvider* BNRegisterSecretsProvider(
    const char* name, BNSecretsProviderCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNSecretsProvider** BNGetSecretsProviderList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeSecretsProviderList(
    BNSecretsProvider** providers) {}
BINARYNINJACOREAPI BNSecretsProvider* BNGetSecretsProviderByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSecretsProviderName(BNSecretsProvider* provider) {
  return {};
}
BINARYNINJACOREAPI bool BNSecretsProviderHasData(BNSecretsProvider* provider,
                                                 const char* key) {
  return {};
}
BINARYNINJACOREAPI char* BNGetSecretsProviderData(BNSecretsProvider* provider,
                                                  const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNStoreSecretsProviderData(BNSecretsProvider* provider,
                                                   const char* key,
                                                   const char* data) {
  return {};
}
BINARYNINJACOREAPI bool BNDeleteSecretsProviderData(BNSecretsProvider* provider,
                                                    const char* key) {
  return {};
}
BINARYNINJACOREAPI BNSymbolQueue* BNCreateSymbolQueue(void) { return {}; }
BINARYNINJACOREAPI void BNDestroySymbolQueue(BNSymbolQueue* queue) {}
BINARYNINJACOREAPI void BNAppendSymbolQueue(
    BNSymbolQueue* queue,
    void (*resolve)(void* ctxt, BNSymbol** symbol, BNTypeWithConfidence* type),
    void* resolveContext,
    void (*add)(void* ctxt, BNSymbol* symbol, BNTypeWithConfidence* type),
    void* addContext) {}
BINARYNINJACOREAPI void BNProcessSymbolQueue(BNSymbolQueue* queue) {}
BINARYNINJACOREAPI bool BNCoreEnumToString(const char* enumName, size_t value,
                                           char** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCoreEnumFromString(const char* enumName,
                                             const char* value,
                                             size_t* result) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchive* BNNewTypeArchiveReference(
    BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeArchiveReference(BNTypeArchive* archive) {}
BINARYNINJACOREAPI void BNFreeTypeArchiveList(BNTypeArchive** archives,
                                              size_t count) {}
BINARYNINJACOREAPI BNTypeArchive* BNOpenTypeArchive(const char* path) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchive* BNCreateTypeArchive(const char* path,
                                                      BNPlatform* platform) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchive* BNCreateTypeArchiveWithId(
    const char* path, BNPlatform* platform, const char* id) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchive* BNLookupTypeArchiveById(const char* id) {
  return {};
}
BINARYNINJACOREAPI void BNCloseTypeArchive(BNTypeArchive* archive) {}
BINARYNINJACOREAPI bool BNIsTypeArchive(const char* path) { return {}; }
BINARYNINJACOREAPI char* BNGetTypeArchiveId(BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeArchivePath(BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI BNPlatform* BNGetTypeArchivePlatform(
    BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeArchiveCurrentSnapshotId(
    BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI void BNSetTypeArchiveCurrentSnapshot(BNTypeArchive* archive,
                                                        const char* id) {}
BINARYNINJACOREAPI char** BNGetTypeArchiveAllSnapshotIds(BNTypeArchive* archive,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveSnapshotParentIds(
    BNTypeArchive* archive, const char* id, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveSnapshotChildIds(
    BNTypeArchive* archive, const char* id, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNTypeContainer* BNGetTypeArchiveTypeContainer(
    BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI bool BNAddTypeArchiveTypes(
    BNTypeArchive* archive, const BNQualifiedNameAndType* types, size_t count) {
  return {};
}
BINARYNINJACOREAPI bool BNRenameTypeArchiveType(
    BNTypeArchive* archive, const char* id, const BNQualifiedName* newName) {
  return {};
}
BINARYNINJACOREAPI bool BNDeleteTypeArchiveType(BNTypeArchive* archive,
                                                const char* id) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetTypeArchiveTypeById(BNTypeArchive* archive,
                                                    const char* id,
                                                    const char* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNType* BNGetTypeArchiveTypeByName(
    BNTypeArchive* archive, const BNQualifiedName* name, const char* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNGetTypeArchiveTypeId(BNTypeArchive* archive,
                                                const BNQualifiedName* name,
                                                const char* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName BNGetTypeArchiveTypeName(
    BNTypeArchive* archive, const char* id, const char* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedNameTypeAndId* BNGetTypeArchiveTypes(
    BNTypeArchive* archive, const char* snapshot, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveTypeIds(BNTypeArchive* archive,
                                                  const char* snapshot,
                                                  size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNQualifiedName* BNGetTypeArchiveTypeNames(
    BNTypeArchive* archive, const char* snapshot, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNGetTypeArchiveTypeNamesAndIds(BNTypeArchive* archive,
                                                        const char* snapshot,
                                                        BNQualifiedName** names,
                                                        char*** ids,
                                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveOutgoingDirectTypeReferences(
    BNTypeArchive* archive, const char* id, const char* snapshot,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveOutgoingRecursiveTypeReferences(
    BNTypeArchive* archive, const char* id, const char* snapshot,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveIncomingDirectTypeReferences(
    BNTypeArchive* archive, const char* id, const char* snapshot,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNGetTypeArchiveIncomingRecursiveTypeReferences(
    BNTypeArchive* archive, const char* id, const char* snapshot,
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeArchiveNewSnapshotTransaction(
    BNTypeArchive* archive, bool (*func)(void* context, const char* id),
    void* context, const char* const* parents, size_t parentCount) {
  return {};
}
BINARYNINJACOREAPI void BNRegisterTypeArchiveNotification(
    BNTypeArchive* archive, BNTypeArchiveNotification* notification) {}
BINARYNINJACOREAPI void BNUnregisterTypeArchiveNotification(
    BNTypeArchive* archive, BNTypeArchiveNotification* notification) {}
BINARYNINJACOREAPI bool BNTypeArchiveStoreMetadata(BNTypeArchive* archive,
                                                   const char* key,
                                                   BNMetadata* value) {
  return {};
}
BINARYNINJACOREAPI BNMetadata* BNTypeArchiveQueryMetadata(
    BNTypeArchive* archive, const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeArchiveRemoveMetadata(BNTypeArchive* archive,
                                                    const char* key) {
  return {};
}
BINARYNINJACOREAPI BNDataBuffer* BNTypeArchiveSerializeSnapshot(
    BNTypeArchive* archive, const char* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeArchiveDeserializeSnapshot(
    BNTypeArchive* archive, BNDataBuffer* buffer) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeArchiveMergeSnapshots(
    BNTypeArchive* archive, const char* baseSnapshot, const char* firstSnapshot,
    const char* secondSnapshot, const char* const* mergeConflictKeysIn,
    const char* const* mergeConflictValuesIn, size_t mergeConflictCountIn,
    char*** mergeConflictsOut, size_t* mergeConflictCountOut, char** result,
    BNProgressFunction progress, void* context) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchive* BNBinaryViewAttachTypeArchive(
    BNBinaryView* view, const char* id, const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewDetachTypeArchive(BNBinaryView* view,
                                                      const char* id) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchive* BNBinaryViewGetTypeArchive(BNBinaryView* view,
                                                             const char* id) {
  return {};
}
BINARYNINJACOREAPI size_t BNBinaryViewGetTypeArchives(BNBinaryView* view,
                                                      char*** ids,
                                                      char*** paths) {
  return {};
}
BINARYNINJACOREAPI char* BNBinaryViewGetTypeArchivePath(BNBinaryView* view,
                                                        const char* id) {
  return {};
}
BINARYNINJACOREAPI size_t BNBinaryViewGetTypeArchiveTypeNameList(
    BNBinaryView* view, BNQualifiedName** names) {
  return {};
}
BINARYNINJACOREAPI size_t BNBinaryViewGetTypeArchiveTypeNames(
    BNBinaryView* view, BNQualifiedName* name, char*** archiveIds,
    char*** archiveTypeIds) {
  return {};
}
BINARYNINJACOREAPI size_t BNBinaryViewGetAssociatedTypeArchiveTypes(
    BNBinaryView* view, char*** typeIds, char*** archiveIds,
    char*** archiveTypeIds) {
  return {};
}
BINARYNINJACOREAPI size_t BNBinaryViewGetAssociatedTypesFromArchive(
    BNBinaryView* view, const char* archiveId, char*** typeIds,
    char*** archiveTypeIds) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewGetAssociatedTypeArchiveTypeTarget(
    BNBinaryView* view, const char* typeId, char** archiveId,
    char** archiveTypeId) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewGetAssociatedTypeArchiveTypeSource(
    BNBinaryView* view, const char* archiveId, const char* archiveTypeId,
    char** typeId) {
  return {};
}
BINARYNINJACOREAPI BNSyncStatus
BNBinaryViewGetTypeArchiveSyncStatus(BNBinaryView* view, const char* typeId) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewDisassociateTypeArchiveType(
    BNBinaryView* view, const char* typeId) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewPullTypeArchiveTypes(
    BNBinaryView* view, const char* archiveId,
    const char* const* archiveTypeIds, size_t archiveTypeIdCount,
    char*** updatedArchiveTypeIds, char*** updatedAnalysisTypeIds,
    size_t* updatedTypeCount) {
  return {};
}
BINARYNINJACOREAPI bool BNBinaryViewPushTypeArchiveTypes(
    BNBinaryView* view, const char* archiveId, const char* const* typeIds,
    size_t typeIdCount, char*** updatedAnalysisTypeIds,
    char*** updatedArchiveTypeIds, size_t* updatedTypeCount) {
  return {};
}
BINARYNINJACOREAPI BNBaseAddressDetection* BNCreateBaseAddressDetection(
    BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI bool BNDetectBaseAddress(
    BNBaseAddressDetection* bad, BNBaseAddressDetectionSettings* settings) {
  return {};
}
BINARYNINJACOREAPI bool BNDetectBaseAddressWithInstructionAnalysis(
    BNBaseAddressDetection* bad,
    BNBaseAddressDetectionInstructionAnalysisSettings* settings) {
  return {};
}
BINARYNINJACOREAPI bool BNDetectBaseAddressWithSampling(
    BNBaseAddressDetection* bad,
    BNBaseAddressDetectionSamplingSettings* settings) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetBaseAddressDetectionScores(
    BNBaseAddressDetection* bad, BNBaseAddressDetectionScore* scores,
    size_t count, BNBaseAddressDetectionConfidence* confidence,
    uint64_t* lastTestedBaseAddress) {
  return {};
}
BINARYNINJACOREAPI BNBaseAddressDetectionReason*
BNGetBaseAddressDetectionReasons(BNBaseAddressDetection* bad,
                                 uint64_t baseAddress, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBaseAddressDetectionReasons(
    BNBaseAddressDetectionReason* reasons) {}
BINARYNINJACOREAPI void BNAbortBaseAddressDetection(
    BNBaseAddressDetection* bad) {}
BINARYNINJACOREAPI bool BNIsBaseAddressDetectionAborted(
    BNBaseAddressDetection* bad) {
  return {};
}
BINARYNINJACOREAPI void BNFreeBaseAddressDetection(
    BNBaseAddressDetection* bad) {}
BINARYNINJACOREAPI bool BNUnicodeGetBlockRange(const char* name,
                                               uint32_t* rangeStart,
                                               uint32_t* rangeEnd) {
  return {};
}
BINARYNINJACOREAPI void BNUnicodeGetBlocksForNames(
    const char* const* names, size_t nameCount, uint32_t*** starts,
    uint32_t*** ends, size_t** blockListCounts, size_t* blockCount) {}
BINARYNINJACOREAPI void BNFreeUnicodeBlockList(uint32_t** starts,
                                               uint32_t** ends,
                                               size_t* blockCounts,
                                               size_t blockListCounts) {}
BINARYNINJACOREAPI void BNUnicodeGetBlockNames(char*** names, size_t* count) {}
BINARYNINJACOREAPI void BNUnicodeGetBlockRanges(char*** names,
                                                uint32_t** rangeStarts,
                                                uint32_t** rangeEnds,
                                                size_t* count) {}
BINARYNINJACOREAPI void BNFreeUnicodeRangeList(uint32_t* starts,
                                               uint32_t* ends) {}
BINARYNINJACOREAPI char* BNUnicodeGetUTF8String(
    uint32_t** starts, uint32_t** ends, size_t* blockListCounts,
    size_t blockCount, const uint8_t* data, const size_t offset,
    const size_t dataLen) {
  return {};
}
BINARYNINJACOREAPI char* BNUnicodeToEscapedString(
    uint32_t** starts, uint32_t** ends, size_t* blockListCounts,
    size_t blockCount, bool utf8Enabled, const void* data,
    const size_t dataLen) {
  return {};
}
BINARYNINJACOREAPI char* BNUnicodeToEscapedStringForView(BNBinaryView* view,
                                                         const void* data,
                                                         size_t dataLen) {
  return {};
}
BINARYNINJACOREAPI size_t BNUnicodeGetDisplayWidth(const char* str) {
  return {};
}
BINARYNINJACOREAPI size_t BNUnicodeGetNextGraphemeClusterBoundary(
    const char* str, size_t len, size_t offset) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationGetActiveRemote() { return {}; }
BINARYNINJACOREAPI void BNCollaborationSetActiveRemote(BNRemote* remote) {}
BINARYNINJACOREAPI bool BNCollaborationStoreDataInKeychain(
    const char* key, const char** dataKeys, const char** dataValues,
    size_t dataCount) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationHasDataInKeychain(const char* key) {
  return {};
}
BINARYNINJACOREAPI size_t BNCollaborationGetDataFromKeychain(
    const char* key, char*** foundKeys, char*** foundValues) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationDeleteDataFromKeychain(const char* key) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationLoadRemotes() { return {}; }
BINARYNINJACOREAPI BNRemote** BNCollaborationGetRemotes(size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationGetRemoteById(
    const char* remoteId) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationGetRemoteByAddress(
    const char* remoteAddress) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationGetRemoteByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationCreateRemote(const char* name,
                                                         const char* address) {
  return {};
}
BINARYNINJACOREAPI void BNCollaborationRemoveRemote(BNRemote* remote) {}
BINARYNINJACOREAPI void BNCollaborationSaveRemotes() {}
BINARYNINJACOREAPI bool BNCollaborationSyncDatabase(
    BNFileMetadata* metadata, BNRemoteFile* file,
    BNCollaborationAnalysisConflictHandler conflictHandler,
    void* conflictHandlerCtxt, BNProgressFunction progress, void* progressCtxt,
    BNCollaborationNameChangesetFunction nameChangeset,
    void* nameChangesetCtxt) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSyncTypeArchive(
    BNTypeArchive* archive, BNRemoteFile* file,
    bool (*conflictHandler)(void*, BNTypeArchiveMergeConflict** conflicts,
                            size_t conflictCount),
    void* conflictHandlerCtxt, BNProgressFunction progress,
    void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationPushTypeArchive(
    BNTypeArchive* archive, BNRemoteFile* file, size_t* count,
    BNProgressFunction progress, void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationPullTypeArchive(
    BNTypeArchive* archive, BNRemoteFile* file, size_t* count,
    bool (*conflictHandler)(void*, BNTypeArchiveMergeConflict** conflicts,
                            size_t conflictCount),
    void* conflictHandlerCtxt, BNProgressFunction progress,
    void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationIsCollaborationTypeArchive(
    BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationGetRemoteForLocalTypeArchive(
    BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject*
BNCollaborationGetRemoteProjectForLocalTypeArchive(BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile*
BNCollaborationGetRemoteFileForLocalTypeArchive(BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot*
BNCollaborationGetRemoteSnapshotFromLocalTypeArchive(BNTypeArchive* archive,
                                                     const char* snapshotId) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationGetLocalSnapshotFromRemoteTypeArchive(
    BNCollaborationSnapshot* snapshot, BNTypeArchive* archive) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationIsTypeArchiveSnapshotIgnored(
    BNTypeArchive* archive, const char* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSetSnapshotAuthor(BNDatabase* database,
                                                         BNSnapshot* snapshot,
                                                         const char* author) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationDefaultProjectPath(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationDefaultFilePath(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI BNFileMetadata* BNCollaborationDownloadFile(
    BNRemoteFile* file, const char* dbPath, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNCollaborationUploadDatabase(
    BNFileMetadata* metadata, BNRemoteProject* project, BNRemoteFolder* folder,
    BNProgressFunction progress, void* progressContext,
    BNCollaborationNameChangesetFunction nameChangeset,
    void* nameChangesetContext) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationIsCollaborationDatabase(
    BNDatabase* database) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGetRemoteForLocalDatabase(
    BNDatabase* database, BNRemote** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGetRemoteProjectForLocalDatabase(
    BNDatabase* database, BNRemoteProject** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGetRemoteFileForLocalDatabase(
    BNDatabase* database, BNRemoteFile** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationAssignSnapshotMap(
    BNSnapshot* localSnapshot, BNCollaborationSnapshot* remoteSnapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGetRemoteSnapshotFromLocal(
    BNSnapshot* snapshot, BNCollaborationSnapshot** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGetLocalSnapshotFromRemote(
    BNCollaborationSnapshot* snapshot, BNDatabase* database,
    BNSnapshot** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationDownloadTypeArchive(
    BNRemoteFile* file, const char* dbPath, BNProgressFunction progress,
    void* progressContext, BNTypeArchive** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUploadTypeArchive(
    BNTypeArchive* archive, BNRemoteProject* project, BNRemoteFolder* folder,
    BNProgressFunction progress, void* progressContext, BNProjectFile* coreFile,
    BNRemoteFile** result) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationDownloadDatabaseForFile(
    BNRemoteFile* file, const char* dbPath, bool force,
    BNProgressFunction progress, void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot* BNCollaborationMergeSnapshots(
    BNSnapshot* first, BNSnapshot* second,
    BNCollaborationAnalysisConflictHandler conflictHandler,
    void* conflictHandlerCtxt, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationPullDatabase(
    BNDatabase* database, BNRemoteFile* file, size_t* count,
    BNCollaborationAnalysisConflictHandler conflictHandler,
    void* conflictHandlerCtxt, BNProgressFunction progress,
    void* progressContext, BNCollaborationNameChangesetFunction nameChangeset,
    void* nameChangesetContext) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationMergeDatabase(
    BNDatabase* database,
    BNCollaborationAnalysisConflictHandler conflictHandler,
    void* conflictHandlerCtxt, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationPushDatabase(BNDatabase* database,
                                                    BNRemoteFile* file,
                                                    size_t* count,
                                                    BNProgressFunction progress,
                                                    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationDumpDatabase(BNDatabase* database) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationIgnoreSnapshot(BNDatabase* database,
                                                      BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationIsSnapshotIgnored(BNDatabase* database,
                                                         BNSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGetSnapshotAuthor(BNDatabase* database,
                                                         BNSnapshot* snapshot,
                                                         char** result) {
  return {};
}
BINARYNINJACOREAPI void BNCollaborationFreeIdList(uint64_t* ids, size_t size) {}
BINARYNINJACOREAPI void BNCollaborationFreeSnapshotIdList(int64_t* ids,
                                                          size_t size) {}
BINARYNINJACOREAPI BNCollaborationLazyT* BNCollaborationLazyTCreate(
    void* (*ctor)(void*), void* context) {
  return {};
}
BINARYNINJACOREAPI void* BNCollaborationLazyTDereference(
    BNCollaborationLazyT* lazyT) {
  return {};
}
BINARYNINJACOREAPI void BNCollaborationFreeLazyT(BNCollaborationLazyT* lazyT) {}
BINARYNINJACOREAPI BNRemote* BNNewRemoteReference(BNRemote* remote) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRemote(BNRemote* remote) {}
BINARYNINJACOREAPI void BNFreeRemoteList(BNRemote** remotes, size_t count) {}
BINARYNINJACOREAPI char* BNRemoteGetUniqueId(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI char* BNRemoteGetName(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI char* BNRemoteGetAddress(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI bool BNRemoteHasLoadedMetadata(BNRemote* remote) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteIsConnected(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI char* BNRemoteGetUsername(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI char* BNRemoteGetToken(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI int BNRemoteGetServerVersion(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI BNVersionInfo
BNRemoteGetServerBuildVersion(BNRemote* remote) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteGetServerBuildId(BNRemote* remote) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteGetAuthBackends(BNRemote* remote,
                                                char*** backendIds,
                                                char*** backendNames,
                                                size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteHasPulledProjects(BNRemote* remote) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteHasPulledUsers(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI bool BNRemoteHasPulledGroups(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI bool BNRemoteIsAdmin(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI bool BNRemoteIsEnterprise(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI bool BNRemoteLoadMetadata(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI char* BNRemoteRequestAuthenticationToken(
    BNRemote* remote, const char* username, const char* password) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteConnect(BNRemote* remote, const char* username,
                                        const char* token) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteDisconnect(BNRemote* remote) { return {}; }
BINARYNINJACOREAPI BNRemoteProject** BNRemoteGetProjects(BNRemote* remote,
                                                         size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNRemoteGetProjectById(BNRemote* remote,
                                                           const char* id) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNRemoteGetProjectByName(BNRemote* remote,
                                                             const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNRemotePullProjects(BNRemote* remote,
                                             BNProgressFunction progress,
                                             void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNRemoteCreateProject(
    BNRemote* remote, const char* name, const char* description) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNRemoteImportLocalProject(
    BNRemote* remote, BNProject* localProject, BNProgressFunction progress,
    void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI bool BNRemotePushProject(BNRemote* remote,
                                            BNRemoteProject* project,
                                            const char** extraFieldKeys,
                                            const char** extraFieldValues,
                                            size_t extraFieldCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteDeleteProject(BNRemote* remote,
                                              BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationGroup** BNRemoteGetGroups(BNRemote* remote,
                                                            size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationGroup* BNRemoteGetGroupById(BNRemote* remote,
                                                              uint64_t id) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationGroup* BNRemoteGetGroupByName(
    BNRemote* remote, const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteSearchGroups(BNRemote* remote,
                                             const char* prefix,
                                             uint64_t** groupIds,
                                             char*** groupNames,
                                             size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNRemotePullGroups(BNRemote* remote,
                                           BNProgressFunction progress,
                                           void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationGroup* BNRemoteCreateGroup(
    BNRemote* remote, const char* name, BNCollaborationUser** users,
    size_t userCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemotePushGroup(BNRemote* remote,
                                          BNCollaborationGroup* group,
                                          const char** extraFieldKeys,
                                          const char** extraFieldValues,
                                          size_t extraFieldCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteDeleteGroup(BNRemote* remote,
                                            BNCollaborationGroup* group) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser** BNRemoteGetUsers(BNRemote* remote,
                                                          size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser* BNRemoteGetUserById(BNRemote* remote,
                                                            const char* id) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser* BNRemoteGetUserByUsername(
    BNRemote* remote, const char* username) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser* BNRemoteGetCurrentUser(
    BNRemote* remote) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteSearchUsers(BNRemote* remote,
                                            const char* prefix, char*** userIds,
                                            char*** usernames, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFileSearchMatch* BNRemoteFindFiles(BNRemote* remote,
                                                              const char* name,
                                                              size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRemoteFileSearchMatchList(
    BNRemoteFileSearchMatch* matches, size_t count) {}
BINARYNINJACOREAPI bool BNRemotePullUsers(BNRemote* remote,
                                          BNProgressFunction progress,
                                          void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser* BNRemoteCreateUser(
    BNRemote* remote, const char* username, const char* email, bool isActive,
    const char* password, const uint64_t* groupIds, size_t groupIdCount,
    const uint64_t* userPermissionIds, size_t userPermissionIdCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemotePushUser(BNRemote* remote,
                                         BNCollaborationUser* user,
                                         const char** extraFieldKeys,
                                         const char** extraFieldValues,
                                         size_t extraFieldCount) {
  return {};
}
BINARYNINJACOREAPI int BNRemoteRequest(BNRemote* remote, void* request,
                                       void* ret) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationGroup* BNNewCollaborationGroupReference(
    BNCollaborationGroup* group) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCollaborationGroup(BNCollaborationGroup* group) {}
BINARYNINJACOREAPI void BNFreeCollaborationGroupList(
    BNCollaborationGroup** group, size_t count) {}
BINARYNINJACOREAPI BNRemote* BNCollaborationGroupGetRemote(
    BNCollaborationGroup* group) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationGroupGetUrl(
    BNCollaborationGroup* group) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNCollaborationGroupGetId(BNCollaborationGroup* group) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationGroupGetName(
    BNCollaborationGroup* group) {
  return {};
}
BINARYNINJACOREAPI void BNCollaborationGroupSetName(BNCollaborationGroup* group,
                                                    const char* name) {}
BINARYNINJACOREAPI BNCollaborationUser** BNCollaborationGroupGetUsers(
    BNCollaborationGroup* group, size_t* count) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGroupSetUsers(
    BNCollaborationGroup* group, BNCollaborationUser** users, size_t count) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationGroupContainsUser(
    BNCollaborationGroup* group, BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser* BNNewCollaborationUserReference(
    BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCollaborationUser(BNCollaborationUser* user) {}
BINARYNINJACOREAPI void BNFreeCollaborationUserList(BNCollaborationUser** users,
                                                    size_t count) {}
BINARYNINJACOREAPI BNRemote* BNCollaborationUserGetRemote(
    BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationUserGetUrl(BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationUserGetId(BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationUserGetUsername(
    BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationUserGetEmail(
    BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationUserGetLastLogin(
    BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUserIsActive(BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUserSetUsername(
    BNCollaborationUser* user, const char* username) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUserSetEmail(BNCollaborationUser* user,
                                                    const char* email) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUserSetIsActive(
    BNCollaborationUser* user, bool isActive) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNNewRemoteProjectReference(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRemoteProject(BNRemoteProject* project) {}
BINARYNINJACOREAPI void BNFreeRemoteProjectList(BNRemoteProject** projects,
                                                size_t count) {}
BINARYNINJACOREAPI BNProject* BNRemoteProjectGetCoreProject(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectIsOpen(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectOpen(BNRemoteProject* project,
                                            BNProgressFunction progress,
                                            void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI void BNRemoteProjectClose(BNRemoteProject* project) {}
BINARYNINJACOREAPI BNRemote* BNRemoteProjectGetRemote(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteProjectGetUrl(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI int64_t BNRemoteProjectGetCreated(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI int64_t
BNRemoteProjectGetLastModified(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteProjectGetId(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteProjectGetName(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectSetName(BNRemoteProject* project,
                                               const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteProjectGetDescription(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectSetDescription(BNRemoteProject* project,
                                                      const char* description) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNRemoteProjectGetReceivedFileCount(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNRemoteProjectGetReceivedFolderCount(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectHasPulledFiles(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectHasPulledFolders(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectHasPulledGroupPermissions(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectHasPulledUserPermissions(
    BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectIsAdmin(BNRemoteProject* project) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile** BNRemoteProjectGetFiles(
    BNRemoteProject* project, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNRemoteProjectGetFileById(
    BNRemoteProject* project, const char* id) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNRemoteProjectGetFileByName(
    BNRemoteProject* project, const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPullFiles(BNRemoteProject* project,
                                                 BNProgressFunction progress,
                                                 void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNRemoteProjectCreateFile(
    BNRemoteProject* project, const char* filename, uint8_t* contents,
    size_t contentsSize, const char* name, const char* description,
    BNRemoteFolder* folder, BNRemoteFileType type, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPushFile(BNRemoteProject* project,
                                                BNRemoteFile* file,
                                                const char** extraFieldKeys,
                                                const char** extraFieldValues,
                                                size_t extraFieldCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectDeleteFile(BNRemoteProject* project,
                                                  BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFolder** BNRemoteProjectGetFolders(
    BNRemoteProject* project, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFolder* BNRemoteProjectGetFolderById(
    BNRemoteProject* project, const char* id) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPullFolders(BNRemoteProject* project,
                                                   BNProgressFunction progress,
                                                   void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFolder* BNRemoteProjectCreateFolder(
    BNRemoteProject* project, const char* name, const char* description,
    BNRemoteFolder* parent, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPushFolder(BNRemoteProject* project,
                                                  BNRemoteFolder* folder,
                                                  const char** extraFieldKeys,
                                                  const char** extraFieldValues,
                                                  size_t extraFieldCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectDeleteFolder(BNRemoteProject* project,
                                                    BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermission**
BNRemoteProjectGetGroupPermissions(BNRemoteProject* project, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermission**
BNRemoteProjectGetUserPermissions(BNRemoteProject* project, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermission* BNRemoteProjectGetPermissionById(
    BNRemoteProject* project, const char* id) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPullGroupPermissions(
    BNRemoteProject* project, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPullUserPermissions(
    BNRemoteProject* project, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermission*
BNRemoteProjectCreateGroupPermission(BNRemoteProject* project, int64_t groupId,
                                     BNCollaborationPermissionLevel level,
                                     BNProgressFunction progress,
                                     void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermission*
BNRemoteProjectCreateUserPermission(BNRemoteProject* project,
                                    const char* userId,
                                    BNCollaborationPermissionLevel level,
                                    BNProgressFunction progress,
                                    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectPushPermission(
    BNRemoteProject* project, BNCollaborationPermission* permission,
    const char** extraFieldKeys, const char** extraFieldValues,
    size_t extraFieldCount) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectDeletePermission(
    BNRemoteProject* project, BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectCanUserView(BNRemoteProject* project,
                                                   BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectCanUserEdit(BNRemoteProject* project,
                                                   BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteProjectCanUserAdmin(BNRemoteProject* project,
                                                    BNCollaborationUser* user) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNNewRemoteFileReference(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRemoteFile(BNRemoteFile* file) {}
BINARYNINJACOREAPI void BNFreeRemoteFileList(BNRemoteFile** files,
                                             size_t count) {}
BINARYNINJACOREAPI BNProjectFile* BNRemoteFileGetCoreFile(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNRemoteFileGetProject(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFolder* BNRemoteFileGetFolder(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNRemoteFileGetRemote(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetUrl(BNRemoteFile* file) { return {}; }
BINARYNINJACOREAPI char* BNRemoteFileGetChatLogUrl(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetUserPositionsUrl(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetId(BNRemoteFile* file) { return {}; }
BINARYNINJACOREAPI BNRemoteFileType BNRemoteFileGetType(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI int64_t BNRemoteFileGetCreated(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetCreatedBy(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI int64_t BNRemoteFileGetLastModified(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI int64_t BNRemoteFileGetLastSnapshot(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetLastSnapshotBy(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetLastSnapshotName(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetHash(BNRemoteFile* file) { return {}; }
BINARYNINJACOREAPI char* BNRemoteFileGetName(BNRemoteFile* file) { return {}; }
BINARYNINJACOREAPI char* BNRemoteFileGetDescription(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileGetMetadata(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNRemoteFileGetSize(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileHasPulledSnapshots(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileSetName(BNRemoteFile* file,
                                            const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileSetDescription(BNRemoteFile* file,
                                                   const char* description) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileSetFolder(BNRemoteFile* file,
                                              BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileSetMetadata(BNRemoteFile* file,
                                                const char* metadata) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot** BNRemoteFileGetSnapshots(
    BNRemoteFile* file, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot* BNRemoteFileGetSnapshotById(
    BNRemoteFile* file, const char* id) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFilePullSnapshots(BNRemoteFile* file,
                                                  BNProgressFunction progress,
                                                  void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot* BNRemoteFileCreateSnapshot(
    BNRemoteFile* file, const char* name, uint8_t* contents,
    size_t contentsSize, uint8_t* analysisCacheContents,
    size_t analysisCacheContentsSize, uint8_t* fileContents,
    size_t fileContentsSize, const char** parentIds, size_t parentIdCount,
    BNProgressFunction progress, void* progressContext) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileDeleteSnapshot(
    BNRemoteFile* file, BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileDownload(BNRemoteFile* file,
                                             BNProgressFunction progress,
                                             void* progressCtxt) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFileDownloadContents(
    BNRemoteFile* file, BNProgressFunction progress, void* progressCtxt,
    uint8_t** data, size_t* size) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileRequestUserPositions(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFileRequestChatLog(BNRemoteFile* file) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFolder* BNNewRemoteFolderReference(
    BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRemoteFolder(BNRemoteFolder* folder) {}
BINARYNINJACOREAPI void BNFreeRemoteFolderList(BNRemoteFolder** folders,
                                               size_t count) {}
BINARYNINJACOREAPI BNProjectFolder* BNRemoteFolderGetCoreFolder(
    BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNRemoteFolderGetProject(
    BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNRemoteFolderGetRemote(BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFolderGetParent(BNRemoteFolder* folder,
                                                BNRemoteFolder** parent) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFolderGetUrl(BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFolderGetId(BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFolderGetParentId(BNRemoteFolder* folder,
                                                  char** result) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFolderGetName(BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI char* BNRemoteFolderGetDescription(BNRemoteFolder* folder) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFolderSetName(BNRemoteFolder* folder,
                                              const char* name) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFolderSetDescription(BNRemoteFolder* folder,
                                                     const char* description) {
  return {};
}
BINARYNINJACOREAPI bool BNRemoteFolderSetParent(BNRemoteFolder* folder,
                                                BNRemoteFolder* parent) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermission*
BNNewCollaborationPermissionReference(BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCollaborationPermission(
    BNCollaborationPermission* permission) {}
BINARYNINJACOREAPI void BNFreeCollaborationPermissionList(
    BNCollaborationPermission** permissions, size_t count) {}
BINARYNINJACOREAPI BNRemoteProject* BNCollaborationPermissionGetProject(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationPermissionGetRemote(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationPermissionGetId(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationPermissionGetUrl(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNCollaborationPermissionGetGroupId(BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationPermissionGetGroupName(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationPermissionGetUserId(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationPermissionGetUsername(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationPermissionLevel
BNCollaborationPermissionGetLevel(BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI void BNCollaborationPermissionSetLevel(
    BNCollaborationPermission* permission,
    BNCollaborationPermissionLevel level) {}
BINARYNINJACOREAPI bool BNCollaborationPermissionCanView(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationPermissionCanEdit(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationPermissionCanAdmin(
    BNCollaborationPermission* permission) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisMergeConflict* BNNewAnalysisMergeConflictReference(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAnalysisMergeConflict(
    BNAnalysisMergeConflict* conflict) {}
BINARYNINJACOREAPI void BNFreeAnalysisMergeConflictList(
    BNAnalysisMergeConflict** conflicts, size_t count) {}
BINARYNINJACOREAPI BNDatabase* BNAnalysisMergeConflictGetDatabase(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetType(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetKey(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNMergeConflictDataType
BNAnalysisMergeConflictGetDataType(BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetBase(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetFirst(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetSecond(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNFileMetadata* BNAnalysisMergeConflictGetBaseFile(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNFileMetadata* BNAnalysisMergeConflictGetFirstFile(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNFileMetadata* BNAnalysisMergeConflictGetSecondFile(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot* BNAnalysisMergeConflictGetBaseSnapshot(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot* BNAnalysisMergeConflictGetFirstSnapshot(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI BNSnapshot* BNAnalysisMergeConflictGetSecondSnapshot(
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetPathItemString(
    BNAnalysisMergeConflict* conflict, const char* path) {
  return {};
}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictGetPathItemSerialized(
    BNAnalysisMergeConflict* conflict, const char* path) {
  return {};
}
BINARYNINJACOREAPI void* BNAnalysisMergeConflictGetPathItem(
    BNAnalysisMergeConflict* conflict, const char* path) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisMergeConflictSuccess(
    BNAnalysisMergeConflict* conflict, const char* value) {
  return {};
}
BINARYNINJACOREAPI BNTypeArchiveMergeConflict*
BNNewTypeArchiveMergeConflictReference(BNTypeArchiveMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI void BNFreeTypeArchiveMergeConflict(
    BNTypeArchiveMergeConflict* conflict) {}
BINARYNINJACOREAPI void BNFreeTypeArchiveMergeConflictList(
    BNTypeArchiveMergeConflict** conflicts, size_t count) {}
BINARYNINJACOREAPI BNTypeArchive* BNTypeArchiveMergeConflictGetTypeArchive(
    BNTypeArchiveMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeArchiveMergeConflictGetTypeId(
    BNTypeArchiveMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeArchiveMergeConflictGetBaseSnapshotId(
    BNTypeArchiveMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeArchiveMergeConflictGetFirstSnapshotId(
    BNTypeArchiveMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI char* BNTypeArchiveMergeConflictGetSecondSnapshotId(
    BNTypeArchiveMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI bool BNTypeArchiveMergeConflictSuccess(
    BNTypeArchiveMergeConflict* conflict, const char* value) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot* BNNewCollaborationSnapshotReference(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCollaborationSnapshot(
    BNCollaborationSnapshot* snapshot) {}
BINARYNINJACOREAPI void BNFreeCollaborationSnapshotList(
    BNCollaborationSnapshot** snapshots, size_t count) {}
BINARYNINJACOREAPI BNRemoteFile* BNCollaborationSnapshotGetFile(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNCollaborationSnapshotGetProject(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationSnapshotGetRemote(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetUrl(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetId(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetName(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetAuthor(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI int64_t
BNCollaborationSnapshotGetCreated(BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI int64_t
BNCollaborationSnapshotGetLastModified(BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetHash(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetSnapshotFileHash(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotHasPulledUndoEntries(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotIsFinalized(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char** BNCollaborationSnapshotGetParentIds(
    BNCollaborationSnapshot* snapshot, size_t* count) {
  return {};
}
BINARYNINJACOREAPI char** BNCollaborationSnapshotGetChildIds(
    BNCollaborationSnapshot* snapshot, size_t* count) {
  return {};
}
BINARYNINJACOREAPI uint64_t BNCollaborationSnapshotGetAnalysisCacheBuildId(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetTitle(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetDescription(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationSnapshotGetAuthorUsername(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot** BNCollaborationSnapshotGetParents(
    BNCollaborationSnapshot* snapshot, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationSnapshot** BNCollaborationSnapshotGetChildren(
    BNCollaborationSnapshot* snapshot, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUndoEntry**
BNCollaborationSnapshotGetUndoEntries(BNCollaborationSnapshot* snapshot,
                                      size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUndoEntry*
BNCollaborationSnapshotGetUndoEntryById(BNCollaborationSnapshot* snapshot,
                                        uint64_t id) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotPullUndoEntries(
    BNCollaborationSnapshot* snapshot, BNProgressFunction progress,
    void* progressContext) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUndoEntry*
BNCollaborationSnapshotCreateUndoEntry(BNCollaborationSnapshot* snapshot,
                                       bool hasParent, uint64_t parent,
                                       const char* data) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotFinalize(
    BNCollaborationSnapshot* snapshot) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotDownloadSnapshotFile(
    BNCollaborationSnapshot* snapshot, BNProgressFunction progress,
    void* progressContext, uint8_t** data, size_t* size) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotDownload(
    BNCollaborationSnapshot* snapshot, BNProgressFunction progress,
    void* progressContext, uint8_t** data, size_t* size) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationSnapshotDownloadAnalysisCache(
    BNCollaborationSnapshot* snapshot, BNProgressFunction progress,
    void* progressContext, uint8_t** data, size_t* size) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUndoEntry*
BNNewCollaborationUndoEntryReference(BNCollaborationUndoEntry* entry) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCollaborationUndoEntry(
    BNCollaborationUndoEntry* entry) {}
BINARYNINJACOREAPI void BNFreeCollaborationUndoEntryList(
    BNCollaborationUndoEntry** entries, size_t count) {}
BINARYNINJACOREAPI BNCollaborationSnapshot* BNCollaborationUndoEntryGetSnapshot(
    BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNCollaborationUndoEntryGetFile(
    BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI BNRemoteProject* BNCollaborationUndoEntryGetProject(
    BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI BNRemote* BNCollaborationUndoEntryGetRemote(
    BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationUndoEntryGetUrl(
    BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI uint64_t
BNCollaborationUndoEntryGetId(BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUndoEntryGetParentId(
    BNCollaborationUndoEntry* undoEntry, uint64_t* parentId) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationUndoEntryGetData(
    BNCollaborationUndoEntry* undoEntry, char** data) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUndoEntry* BNCollaborationUndoEntryGetParent(
    BNCollaborationUndoEntry* undoEntry) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationChangeset*
BNNewCollaborationChangesetReference(BNCollaborationChangeset* changeset) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCollaborationChangeset(
    BNCollaborationChangeset* changeset) {}
BINARYNINJACOREAPI void BNFreeCollaborationChangesetList(
    BNCollaborationChangeset** changesets, size_t count) {}
BINARYNINJACOREAPI BNDatabase* BNCollaborationChangesetGetDatabase(
    BNCollaborationChangeset* changeset) {
  return {};
}
BINARYNINJACOREAPI BNRemoteFile* BNCollaborationChangesetGetFile(
    BNCollaborationChangeset* changeset) {
  return {};
}
BINARYNINJACOREAPI int64_t* BNCollaborationChangesetGetSnapshotIds(
    BNCollaborationChangeset* changeset, size_t* count) {
  return {};
}
BINARYNINJACOREAPI BNCollaborationUser* BNCollaborationChangesetGetAuthor(
    BNCollaborationChangeset* changeset) {
  return {};
}
BINARYNINJACOREAPI char* BNCollaborationChangesetGetName(
    BNCollaborationChangeset* changeset) {
  return {};
}
BINARYNINJACOREAPI bool BNCollaborationChangesetSetName(
    BNCollaborationChangeset* changeset, const char* name) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisMergeConflictSplitter*
BNRegisterAnalysisMergeConflictSplitter(
    BNAnalysisMergeConflictSplitterCallbacks* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNAnalysisMergeConflictSplitter**
BNGetAnalysisMergeConflictSplitterList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeAnalysisMergeConflictSplitterList(
    BNAnalysisMergeConflictSplitter** splitters, size_t count) {}
BINARYNINJACOREAPI char* BNAnalysisMergeConflictSplitterGetName(
    BNAnalysisMergeConflictSplitter* splitter) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisMergeConflictSplitterCanSplit(
    BNAnalysisMergeConflictSplitter* splitter, const char* key,
    BNAnalysisMergeConflict* conflict) {
  return {};
}
BINARYNINJACOREAPI bool BNAnalysisMergeConflictSplitterSplit(
    BNAnalysisMergeConflictSplitter* splitter, const char* originalKey,
    BNAnalysisMergeConflict* originalConflict, BNKeyValueStore* result,
    char*** newKeys, BNAnalysisMergeConflict*** newConflicts,
    size_t* newCount) {
  return {};
}
BINARYNINJACOREAPI BNHighLevelILTokenEmitter*
BNNewHighLevelILTokenEmitterReference(BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI void BNHighLevelILTokenPrependCollapseBlankIndicator(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenPrependCollapseIndicator(
    BNHighLevelILTokenEmitter* emitter, BNInstructionTextTokenContext context,
    uint64_t hash) {}
BINARYNINJACOREAPI bool BNHighLevelILTokenEmitterHasCollapsableRegions(
    BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterSetHasCollapsableRegions(
    BNHighLevelILTokenEmitter* emitter, bool state) {}
BINARYNINJACOREAPI void BNFreeHighLevelILTokenEmitter(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppend(
    BNHighLevelILTokenEmitter* emitter, BNInstructionTextToken* token) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterInitLine(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterNewLine(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterIncreaseIndent(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterDecreaseIndent(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterScopeSeparator(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterBeginScope(
    BNHighLevelILTokenEmitter* emitter, BNScopeType type) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterEndScope(
    BNHighLevelILTokenEmitter* emitter, BNScopeType type) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterScopeContinuation(
    BNHighLevelILTokenEmitter* emitter, bool forceSameLine) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterFinalizeScope(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterNoIndentForThisLine(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterBeginForceZeroConfidence(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterEndForceZeroConfidence(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI BNTokenEmitterExpr BNHighLevelILTokenEmitterSetCurrentExpr(
    BNHighLevelILTokenEmitter* emitter, BNTokenEmitterExpr expr) {
  return {};
}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterRestoreCurrentExpr(
    BNHighLevelILTokenEmitter* emitter, BNTokenEmitterExpr expr) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterFinalize(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendOpenParen(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendCloseParen(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendOpenBracket(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendCloseBracket(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendOpenBrace(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendCloseBrace(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterAppendSemicolon(
    BNHighLevelILTokenEmitter* emitter) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterSetBraceRequirement(
    BNHighLevelILTokenEmitter* emitter, BNBraceRequirement required) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterSetBracesAroundSwitchCases(
    BNHighLevelILTokenEmitter* emitter, bool braces) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterSetDefaultBracesOnSameLine(
    BNHighLevelILTokenEmitter* emitter, bool sameLine) {}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterSetSimpleScopeAllowed(
    BNHighLevelILTokenEmitter* emitter, bool allowed) {}
BINARYNINJACOREAPI BNBraceRequirement
BNHighLevelILTokenEmitterGetBraceRequirement(
    BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI bool BNHighLevelILTokenEmitterHasBracesAroundSwitchCases(
    BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI bool BNHighLevelILTokenEmitterGetDefaultBracesOnSameLine(
    BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI size_t
BNHighLevelILTokenEmitterGetMaxTernarySimplficationTokens(
    BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI bool BNHighLevelILTokenEmitterIsSimpleScopeAllowed(
    BNHighLevelILTokenEmitter* emitter) {
  return {};
}
BINARYNINJACOREAPI BNInstructionTextToken*
BNHighLevelILTokenEmitterGetCurrentTokens(BNHighLevelILTokenEmitter* emitter,
                                          size_t* tokenCount) {
  return {};
}
BINARYNINJACOREAPI void BNHighLevelILTokenEmitterSetCurrentTokens(
    BNHighLevelILTokenEmitter* emitter, BNInstructionTextToken* tokens,
    size_t tokenCount) {}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNHighLevelILTokenEmitterGetLines(
    BNHighLevelILTokenEmitter* emitter, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNAddHighLevelILSizeToken(
    size_t size, BNInstructionTextTokenType type,
    BNHighLevelILTokenEmitter* tokens) {}
BINARYNINJACOREAPI void BNAddHighLevelILFloatSizeToken(
    size_t size, BNInstructionTextTokenType type,
    BNHighLevelILTokenEmitter* tokens) {}
BINARYNINJACOREAPI void BNAddHighLevelILVarTextToken(
    BNHighLevelILFunction* func, const BNVariable* var,
    BNHighLevelILTokenEmitter* tokens, size_t exprIndex, size_t size) {}
BINARYNINJACOREAPI void BNAddHighLevelILIntegerTextToken(
    BNHighLevelILFunction* func, size_t exprIndex, int64_t val, size_t size,
    BNHighLevelILTokenEmitter* tokens) {}
BINARYNINJACOREAPI void BNAddHighLevelILArrayIndexToken(
    BNHighLevelILFunction* func, size_t exprIndex, int64_t val, size_t size,
    BNHighLevelILTokenEmitter* tokens, uint64_t address) {}
BINARYNINJACOREAPI BNSymbolDisplayResult BNAddHighLevelILPointerTextToken(
    BNHighLevelILFunction* func, size_t exprIndex, int64_t val,
    BNHighLevelILTokenEmitter* tokens, BNDisassemblySettings* settings,
    BNSymbolDisplayType symbolDisplay, BNOperatorPrecedence precedence,
    bool allowShortString) {
  return {};
}
BINARYNINJACOREAPI void BNAddHighLevelILConstantTextToken(
    BNHighLevelILFunction* func, size_t exprIndex, int64_t val, size_t size,
    BNHighLevelILTokenEmitter* tokens, BNDisassemblySettings* settings,
    BNOperatorPrecedence precedence) {}
BINARYNINJACOREAPI char** BNAddNamesForOuterStructureMembers(
    BNBinaryView* data, BNType* type, BNHighLevelILFunction* hlil,
    size_t varExpr, size_t* nameCount) {
  return {};
}
BINARYNINJACOREAPI int64_t BNZeroExtend(int64_t value, size_t sourceSize,
                                        size_t destSize) {
  return {};
}
BINARYNINJACOREAPI int64_t BNSignExtend(int64_t value, size_t sourceSize,
                                        size_t destSize) {
  return {};
}
BINARYNINJACOREAPI int64_t BNMaskToSize(int64_t value, size_t size) {
  return {};
}
BINARYNINJACOREAPI int64_t BNGetMaskForSize(size_t size) { return {}; }
BINARYNINJACOREAPI BNFirmwareNinja* BNCreateFirmwareNinja(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFirmwareNinja(BNFirmwareNinja* fn) {}
BINARYNINJACOREAPI bool BNFirmwareNinjaStoreCustomDevice(BNFirmwareNinja* fn,
                                                         const char* name,
                                                         uint64_t start,
                                                         uint64_t end,
                                                         const char* info) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRemoveCustomDevice(BNFirmwareNinja* fn,
                                                          const char* name) {
  return {};
}
BINARYNINJACOREAPI int BNFirmwareNinjaQueryCustomDevices(
    BNFirmwareNinja* fn, BNFirmwareNinjaDevice** devices) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaFreeDevices(
    BNFirmwareNinjaDevice* devices, int size) {}
BINARYNINJACOREAPI int BNFirmwareNinjaQueryBoardNamesForArchitecture(
    BNFirmwareNinja* fn, BNArchitecture* arch, char*** boards) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaFreeBoardNames(char** boards, int size) {
}
BINARYNINJACOREAPI int BNFirmwareNinjaQueryBoardDevices(
    BNFirmwareNinja* fn, BNArchitecture* arch, const char* board,
    BNFirmwareNinjaDevice** devices) {
  return {};
}
BINARYNINJACOREAPI int BNFirmwareNinjaFindSectionsWithEntropy(
    BNFirmwareNinja* fn, BNFirmwareNinjaSection** sections,
    float highCodeEntropyThreshold, float lowCodeEntropyThreshold,
    size_t blockSize, BNFirmwareNinjaSectionAnalysisMode mode) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaFreeSections(
    BNFirmwareNinjaSection* sections, int size) {}
BINARYNINJACOREAPI int BNFirmwareNinjaGetFunctionMemoryAccesses(
    BNFirmwareNinja* fn, BNFirmwareNinjaFunctionMemoryAccesses*** fma,
    BNProgressFunction progress, void* progressContext) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaFreeFunctionMemoryAccesses(
    BNFirmwareNinjaFunctionMemoryAccesses** fma, int size) {}
BINARYNINJACOREAPI void BNFirmwareNinjaStoreFunctionMemoryAccessesToMetadata(
    BNFirmwareNinja* fn, BNFirmwareNinjaFunctionMemoryAccesses** fma,
    int size) {}
BINARYNINJACOREAPI int BNFirmwareNinjaQueryFunctionMemoryAccessesFromMetadata(
    BNFirmwareNinja* fn, BNFirmwareNinjaFunctionMemoryAccesses*** fma) {
  return {};
}
BINARYNINJACOREAPI int BNFirmwareNinjaGetBoardDeviceAccesses(
    BNFirmwareNinja* fn, BNFirmwareNinjaFunctionMemoryAccesses** fma, int size,
    BNFirmwareNinjaDeviceAccesses** accesses, BNArchitecture* arch) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaFreeBoardDeviceAccesses(
    BNFirmwareNinjaDeviceAccesses* accesses, int size) {}
BINARYNINJACOREAPI BNFirmwareNinjaReferenceNode*
BNFirmwareNinjaGetMemoryRegionReferenceTree(
    BNFirmwareNinja* fn, uint64_t start, uint64_t end,
    BNFirmwareNinjaFunctionMemoryAccesses** fma, int size, uint64_t* value) {
  return {};
}
BINARYNINJACOREAPI BNFirmwareNinjaReferenceNode*
BNFirmwareNinjaGetAddressReferenceTree(
    BNFirmwareNinja* fn, uint64_t address,
    BNFirmwareNinjaFunctionMemoryAccesses** fma, int size, uint64_t* value) {
  return {};
}
BINARYNINJACOREAPI BNFirmwareNinjaRelationship**
BNFirmwareNinjaQueryRelationships(BNFirmwareNinja* fn, size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaFreeRelationships(
    BNFirmwareNinjaRelationship** relationships, size_t count) {}
BINARYNINJACOREAPI void BNFirmwareNinjaAddRelationship(
    BNFirmwareNinja* fn, BNFirmwareNinjaRelationship* rel) {}
BINARYNINJACOREAPI BNFirmwareNinjaRelationship*
BNFirmwareNinjaGetRelationshipByGuid(BNFirmwareNinja* fn, const char* guid) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaRemoveRelationshipByGuid(
    BNFirmwareNinja* fn, const char* guid) {}
BINARYNINJACOREAPI bool BNFirmwareNinjaReferenceNodeIsFunction(
    BNFirmwareNinjaReferenceNode* node) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaReferenceNodeIsDataVariable(
    BNFirmwareNinjaReferenceNode* node) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaReferenceNodeHasChildren(
    BNFirmwareNinjaReferenceNode* node) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNFirmwareNinjaReferenceNodeGetFunction(
    BNFirmwareNinjaReferenceNode* node) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaReferenceNodeGetDataVariable(
    BNFirmwareNinjaReferenceNode* node, BNDataVariable* dataVariable) {
  return {};
}
BINARYNINJACOREAPI BNFirmwareNinjaReferenceNode**
BNFirmwareNinjaReferenceNodeGetChildren(BNFirmwareNinjaReferenceNode* parent,
                                        size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFirmwareNinjaReferenceNode(
    BNFirmwareNinjaReferenceNode* node) {}
BINARYNINJACOREAPI BNFirmwareNinjaReferenceNode*
BNNewFirmwareNinjaReferenceNodeReference(BNFirmwareNinjaReferenceNode* node) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFirmwareNinjaReferenceNodes(
    BNFirmwareNinjaReferenceNode** nodes, size_t count) {}
BINARYNINJACOREAPI BNFirmwareNinjaRelationship*
BNCreateFirmwareNinjaRelationship(BNBinaryView* view) {
  return {};
}
BINARYNINJACOREAPI void BNFreeFirmwareNinjaRelationship(
    BNFirmwareNinjaRelationship* rel) {}
BINARYNINJACOREAPI BNFirmwareNinjaRelationship*
BNNewFirmwareNinjaRelationshipReference(BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetPrimaryAddress(
    BNFirmwareNinjaRelationship* rel, uint64_t address) {}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetPrimaryDataVariable(
    BNFirmwareNinjaRelationship* rel, uint64_t dataVariableAddress) {}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetPrimaryFunction(
    BNFirmwareNinjaRelationship* rel, BNFunction* function) {}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipPrimaryIsDataVariable(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipPrimaryIsFunction(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipPrimaryIsAddress(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipGetPrimaryDataVariable(
    BNFirmwareNinjaRelationship* rel, BNDataVariable* dataVariable) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNFirmwareNinjaRelationshipGetPrimaryFunction(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipGetPrimaryAddress(
    BNFirmwareNinjaRelationship* rel, uint64_t* result) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetSecondaryExternalAddress(
    BNFirmwareNinjaRelationship* rel, BNProjectFile* projectFile,
    uint64_t address) {}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetSecondaryExternalSymbol(
    BNFirmwareNinjaRelationship* rel, BNProjectFile* projectFile,
    const char* symbol) {}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetSecondaryAddress(
    BNFirmwareNinjaRelationship* rel, uint64_t address) {}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetSecondaryDataVariable(
    BNFirmwareNinjaRelationship* rel, uint64_t dataVariableAddress) {}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetSecondaryFunction(
    BNFirmwareNinjaRelationship* rel, BNFunction* function) {}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipSecondaryIsDataVariable(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipSecondaryIsFunction(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipSecondaryIsAddress(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipSecondaryIsExternalAddress(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipSecondaryIsExternalSymbol(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI BNProjectFile*
BNFirmwareNinjaRelationshipGetSecondaryExternalProjectFile(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipGetSecondaryAddress(
    BNFirmwareNinjaRelationship* rel, uint64_t* result) {
  return {};
}
BINARYNINJACOREAPI bool BNFirmwareNinjaRelationshipGetSecondaryDataVariable(
    BNFirmwareNinjaRelationship* rel, BNDataVariable* dataVariable) {
  return {};
}
BINARYNINJACOREAPI BNFunction* BNFirmwareNinjaRelationshipGetSecondaryFunction(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI char* BNFirmwareNinjaRelationshipGetSecondaryExternalSymbol(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetDescription(
    BNFirmwareNinjaRelationship* rel, const char* description) {}
BINARYNINJACOREAPI char* BNFirmwareNinjaRelationshipGetDescription(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI void BNFirmwareNinjaRelationshipSetProvenance(
    BNFirmwareNinjaRelationship* rel, const char* provenance) {}
BINARYNINJACOREAPI char* BNFirmwareNinjaRelationshipGetProvenance(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI char* BNFirmwareNinjaRelationshipGetGuid(
    BNFirmwareNinjaRelationship* rel) {
  return {};
}
BINARYNINJACOREAPI BNLineFormatter* BNRegisterLineFormatter(
    const char* name, BNCustomLineFormatter* callbacks) {
  return {};
}
BINARYNINJACOREAPI BNLineFormatter** BNGetLineFormatterList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLineFormatterList(BNLineFormatter** formatters) {}
BINARYNINJACOREAPI BNLineFormatter* BNGetLineFormatterByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI BNLineFormatter* BNGetDefaultLineFormatter() { return {}; }
BINARYNINJACOREAPI char* BNGetLineFormatterName(BNLineFormatter* formatter) {
  return {};
}
BINARYNINJACOREAPI BNDisassemblyTextLine* BNFormatLines(
    BNLineFormatter* formatter, BNDisassemblyTextLine* inLines, size_t inCount,
    const BNLineFormatterSettings* settings, size_t* outCount) {
  return {};
}
BINARYNINJACOREAPI BNLineFormatterSettings* BNGetDefaultLineFormatterSettings(
    BNDisassemblySettings* settings, BNHighLevelILFunction* func) {
  return {};
}
BINARYNINJACOREAPI BNLineFormatterSettings*
BNGetLanguageRepresentationLineFormatterSettings(
    BNDisassemblySettings* settings, BNLanguageRepresentationFunction* func) {
  return {};
}
BINARYNINJACOREAPI void BNFreeLineFormatterSettings(
    BNLineFormatterSettings* settings) {}
BINARYNINJACOREAPI BNRenderLayer* BNRegisterRenderLayer(
    const char* name, BNRenderLayerCallbacks* callbacks,
    BNRenderLayerDefaultEnableState enableState) {
  return {};
}
BINARYNINJACOREAPI BNRenderLayer** BNGetRenderLayerList(size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeRenderLayerList(BNRenderLayer** renderLayers) {}
BINARYNINJACOREAPI BNRenderLayer* BNGetRenderLayerByName(const char* name) {
  return {};
}
BINARYNINJACOREAPI char* BNGetRenderLayerName(BNRenderLayer* renderLayer) {
  return {};
}
BINARYNINJACOREAPI BNRenderLayerDefaultEnableState
BNGetRenderLayerDefaultEnableState(BNRenderLayer* renderLayer) {
  return {};
}
BINARYNINJACOREAPI void BNApplyRenderLayerToFlowGraph(
    BNRenderLayer* renderLayer, BNFlowGraph* graph) {}
BINARYNINJACOREAPI void BNApplyRenderLayerToLinearViewObject(
    BNRenderLayer* renderLayer, BNLinearViewObject* obj,
    BNLinearViewObject* prev, BNLinearViewObject* next,
    BNLinearDisassemblyLine* inLines, size_t inLineCount,
    BNLinearDisassemblyLine** outLines, size_t* outLineCount) {}
BINARYNINJACOREAPI void BNFreeStringRef(BNStringRef* ref) {}
BINARYNINJACOREAPI BNStringRef* BNDuplicateStringRef(BNStringRef* ref) {
  return {};
}
BINARYNINJACOREAPI const char* BNGetStringRefContents(BNStringRef* ref) {
  return {};
}
BINARYNINJACOREAPI size_t BNGetStringRefSize(BNStringRef* ref) { return {}; }
BINARYNINJACOREAPI BNStringRef* BNCreateStringRef(const char* str) {
  return {};
}
BINARYNINJACOREAPI BNStringRef* BNCreateStringRefOfLength(const char* str,
                                                          size_t len) {
  return {};
}
BINARYNINJACOREAPI BNConstantRenderer* BNRegisterConstantRenderer(
    const char* name, BNCustomConstantRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI BNConstantRenderer* BNGetConstantRendererByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNConstantRenderer** BNGetConstantRendererList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeConstantRendererList(
    BNConstantRenderer** renderers) {}
BINARYNINJACOREAPI char* BNGetConstantRendererName(
    BNConstantRenderer* renderer) {
  return {};
}
BINARYNINJACOREAPI bool BNIsConstantRendererValidForType(
    BNConstantRenderer* renderer, BNHighLevelILFunction* il, BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNConstantRendererRenderConstant(
    BNConstantRenderer* renderer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, int64_t val, BNHighLevelILTokenEmitter* tokens,
    BNDisassemblySettings* settings, BNOperatorPrecedence precedence) {
  return {};
}
BINARYNINJACOREAPI bool BNConstantRendererRenderConstantPointer(
    BNConstantRenderer* renderer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, int64_t val, BNHighLevelILTokenEmitter* tokens,
    BNDisassemblySettings* settings, BNSymbolDisplayType symbolDisplay,
    BNOperatorPrecedence precedence) {
  return {};
}
BINARYNINJACOREAPI BNCustomStringType* BNRegisterCustomStringType(
    BNCustomStringTypeInfo* info) {
  return {};
}
BINARYNINJACOREAPI BNCustomStringType* BNGetCustomStringTypeByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNCustomStringType* BNGetCustomStringTypeByID(uint32_t id) {
  return {};
}
BINARYNINJACOREAPI BNCustomStringType** BNGetCustomStringTypeList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeCustomStringTypeList(BNCustomStringType** types) {
}
BINARYNINJACOREAPI char* BNGetCustomStringTypeName(BNCustomStringType* type) {
  return {};
}
BINARYNINJACOREAPI char* BNGetCustomStringTypePrefix(BNCustomStringType* type) {
  return {};
}
BINARYNINJACOREAPI char* BNGetCustomStringTypePostfix(
    BNCustomStringType* type) {
  return {};
}
BINARYNINJACOREAPI BNStringRecognizer* BNRegisterStringRecognizer(
    const char* name, BNCustomStringRecognizer* recognizer) {
  return {};
}
BINARYNINJACOREAPI BNStringRecognizer* BNGetStringRecognizerByName(
    const char* name) {
  return {};
}
BINARYNINJACOREAPI BNStringRecognizer** BNGetStringRecognizerList(
    size_t* count) {
  return {};
}
BINARYNINJACOREAPI void BNFreeStringRecognizerList(
    BNStringRecognizer** recognizers) {}
BINARYNINJACOREAPI char* BNGetStringRecognizerName(
    BNStringRecognizer* recognizer) {
  return {};
}
BINARYNINJACOREAPI bool BNIsStringRecognizerValidForType(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, BNType* type) {
  return {};
}
BINARYNINJACOREAPI bool BNStringRecognizerRecognizeConstant(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, int64_t val, BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI bool BNStringRecognizerRecognizeConstantPointer(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, int64_t val, BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI bool BNStringRecognizerRecognizeExternPointer(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, int64_t val, uint64_t offset, BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI bool BNStringRecognizerRecognizeImport(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, int64_t val, BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI bool BNStringRecognizerRecognizeConstantData(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, size_t exprIndex,
    BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI bool BNStringRecognizerRecognizeStructInit(
    BNStringRecognizer* recognizer, BNHighLevelILFunction* il, size_t exprIndex,
    BNType* type, const uint64_t* fieldOffsets, const int64_t* fieldValues,
    size_t fieldCount, BNDerivedString* out) {
  return {};
}
BINARYNINJACOREAPI void BNFreePossibleValueSet(BNPossibleValueSet* object) {}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetUnion(const BNPossibleValueSet* object,
                        const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetIntersection(const BNPossibleValueSet* object,
                               const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetAdd(const BNPossibleValueSet* object,
                      const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetSubtract(const BNPossibleValueSet* object,
                           const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetMultiply(const BNPossibleValueSet* object,
                           const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetSignedDivide(const BNPossibleValueSet* object,
                               const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetUnsignedDivide(const BNPossibleValueSet* object,
                                 const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetSignedMod(const BNPossibleValueSet* object,
                            const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetUnsignedMod(const BNPossibleValueSet* object,
                              const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetAnd(const BNPossibleValueSet* object,
                      const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetOr(const BNPossibleValueSet* object,
                     const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetXor(const BNPossibleValueSet* object,
                      const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetShiftLeft(const BNPossibleValueSet* object,
                            const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNPossibleValueSetLogicalShiftRight(
    const BNPossibleValueSet* object, const BNPossibleValueSet* other,
    size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet BNPossibleValueSetArithShiftRight(
    const BNPossibleValueSet* object, const BNPossibleValueSet* other,
    size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetRotateLeft(const BNPossibleValueSet* object,
                             const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetRotateRight(const BNPossibleValueSet* object,
                              const BNPossibleValueSet* other, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetNegate(const BNPossibleValueSet* object, size_t size) {
  return {};
}
BINARYNINJACOREAPI BNPossibleValueSet
BNPossibleValueSetNot(const BNPossibleValueSet* object, size_t size) {
  return {};
}
}  // extern "C"
