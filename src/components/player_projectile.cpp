// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "components/player_projectile.h"

#include "component_library/common_services.h"
#include "component_library/transform.h"
#include "components/services.h"
#include "flatbuffers/flatbuffers.h"
#include "flatbuffers/reflection.h"
#include "pindrop/pindrop.h"

FPL_ENTITY_DEFINE_COMPONENT(fpl::fpl_project::PlayerProjectileComponent,
                            fpl::fpl_project::PlayerProjectileData)

namespace fpl {
namespace fpl_project {

using fpl::component_library::CommonServicesComponent;
using fpl::component_library::TransformComponent;
using fpl::component_library::TransformData;


void PlayerProjectileComponent::AddFromRawData(entity::EntityRef& entity,
                                               const void* /*raw_data*/) {
  AddEntity(entity);
  entity_manager_->AddEntityToComponent<TransformComponent>(entity);
}

}  // fpl_project
}  // fpl
