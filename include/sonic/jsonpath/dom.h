
#pragma once

#include "sonic/dom/generic_document.h"
#include "sonic/jsonpath/dump.h"

namespace sonic_json {
    
sonic_force_inline std::tuple<std::string, SonicError> GetByJsonPath(
    StringView json, StringView jsonpath) {
  // parse json into dom
  Document dom;
  dom.Parse(json);
  if (dom.HasParseError()) {
    return std::make_tuple("", dom.GetParseError());
  }

  // get the nodes
  auto result = dom.AtJsonPath(jsonpath);
  if (result.error != kErrorNone) {
    return std::make_tuple("", result.error);
  }

 return internal::Serialize(result);
}

}