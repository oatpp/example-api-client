
#ifndef DemoApiModels_hpp
#define DemoApiModels_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class MyRequestDto : public oatpp::DTO {
  
  DTO_INIT(MyRequestDto, DTO)
  
  DTO_FIELD(String, message);
  DTO_FIELD(Int32, code);
  
};

class HttpBinResponseDto : public oatpp::DTO {
  
  DTO_INIT(HttpBinResponseDto, DTO)
  
  DTO_FIELD(String, data);
  DTO_FIELD(Fields<String>::ObjectWrapper, headers);
  DTO_FIELD(String, method);
  DTO_FIELD(String, origin);
  DTO_FIELD(String, url);
  
};

#include OATPP_CODEGEN_END(DTO)

#endif /* DemoApiModels_hpp */
