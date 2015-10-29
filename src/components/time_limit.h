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

#ifndef COMPONENTS_TIMELIMIT_H_
#define COMPONENTS_TIMELIMIT_H_

#include "components_generated.h"
#include "entity/component.h"
#include "mathfu/constants.h"
#include "mathfu/glsl_mappings.h"
#include "mathfu/matrix_4x4.h"

namespace fpl {
namespace zooshi {

struct TimeLimitData {
  TimeLimitData() : time_elapsed(0), time_limit(0) {}
  entity::WorldTime time_elapsed;
  entity::WorldTime time_limit;
  mathfu::vec3 original_scale;
};

// Component for limiting how long things stay in the world.  If they have
// a transform component, they'll scale away to nothing.  Otherwise, they'll
// just be removed when their time is up.
class TimeLimitComponent : public entity::Component<TimeLimitData> {
 public:
  TimeLimitComponent() {}

  virtual void AddFromRawData(entity::EntityRef& entity, const void* data);
  virtual RawDataUniquePtr ExportRawData(const entity::EntityRef& entity) const;

  virtual void InitEntity(entity::EntityRef& entity);
  virtual void UpdateAllEntities(entity::WorldTime delta_time);
};

}  // zooshi
}  // fpl

FPL_ENTITY_REGISTER_COMPONENT(fpl::zooshi::TimeLimitComponent,
                              fpl::zooshi::TimeLimitData)

#endif  // COMPONENTS_TIMELIMIT_H_
