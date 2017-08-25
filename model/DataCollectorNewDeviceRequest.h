/**
 * Knetik.io Data Collector REST API
 * <p>Use this API to send application data to Knetik.io including user/device information and transactional events.</p> <p>   Please consult the <a href=\"/doc\">official user documentation</a> to find out how to send data, and how this data is used. <p></p> <h2>Notes</h2> <br> New more ReSTful implementation of the telemetry data collection service. Legacy clients can still use the old API format, but we strongly recommend switching over to this new format. Navigate to the legacy documentation using the dropdown at the top of this page. <p></p> <h2>User IDs and Device IDs</h2> <br> Knetik.io can uniquely associate state, events and transactions to users and/or devices for your application. In order to accomplish this, each API call takes userId and deviceId as parameters in the request object. At least one of these must be provided in the request object, except as explicitly noted. <br> <p></p> <h2>Timestamps</h2> <br> All timestamp parameters must be epoch timestamps in milliseconds. <br> <p></p> <h2>Required Request Headers</h2> <br> The following HTTP header values must be provided for each API call: <ul>   <li>     <b>Content-Type: application/json</b>   </li> </ul> <p></p> <h2>Required Query Parameters</h2> <br> All API calls also require the following query parameters to be present on the URL: <ul>   <li>     <b>customer_id:</b> your unique customer ID   </li> </ul> <p></p> <h2>API Responses</h2> <br> If successful, API calls will simply return an HTTP response code of ACCEPTED (202) with no other data. If errors occur, a JSON payload will be returned containing detailed error information and an appropriate HTTP error status code will be provided (as documented in each of the API methods). <br> <p></p>
 *
 * OpenAPI spec version: 2.0
 * Contact: support@knetik.com
 *
 * NOTE: This class is auto generated by the swagger code generator 2.3.0-SNAPSHOT.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * DataCollectorNewDeviceRequest.h
 *
 * 
 */

#ifndef DataCollectorNewDeviceRequest_H_
#define DataCollectorNewDeviceRequest_H_


#include "ModelBase.h"

#include <cpprest/details/basic_types.h>
#include "Object.h"

namespace io {
namespace knetik {
namespace client {
namespace model {

/// <summary>
/// 
/// </summary>
class  DataCollectorNewDeviceRequest
    : public ModelBase
{
public:
    DataCollectorNewDeviceRequest();
    virtual ~DataCollectorNewDeviceRequest();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DataCollectorNewDeviceRequest members

    /// <summary>
    /// Unique ID of the new device
    /// </summary>
    utility::string_t getDeviceId() const;
        void setDeviceId(utility::string_t value);
    /// <summary>
    /// A key/value list of properties for this event. Values can be numerical, strings or booleans, proper typing matters (quoted vs unquoted)
    /// </summary>
    std::shared_ptr<Object> getEventProperties() const;
    bool eventPropertiesIsSet() const;
    void unsetEvent_properties();
    void setEventProperties(std::shared_ptr<Object> value);
    /// <summary>
    /// Epoch timestamp &lt;i&gt;in milliseconds&lt;/i&gt; of when event itself occurred
    /// </summary>
    int64_t getEventTimestamp() const;
        void setEventTimestamp(int64_t value);
    /// <summary>
    /// Specifies the canonical model name of the request. Ex: DataCollectorNewUserRequest -&gt; newUser, NewEventRequest -&gt; newEvent,e tc
    /// </summary>
    utility::string_t getRequestType() const;
        void setRequestType(utility::string_t value);
    /// <summary>
    /// Epoch timestamp &lt;i&gt;in milliseconds&lt;/i&gt; of when event was sent to the API
    /// </summary>
    int64_t getSendTimestamp() const;
        void setSendTimestamp(int64_t value);
    /// <summary>
    /// Unique ID of the user triggering the event
    /// </summary>
    utility::string_t getUserId() const;
    bool userIdIsSet() const;
    void unsetUser_id();
    void setUserId(utility::string_t value);

protected:
    utility::string_t m_Device_id;
        std::shared_ptr<Object> m_Event_properties;
    bool m_Event_propertiesIsSet;
    int64_t m_Event_timestamp;
        utility::string_t m_Request_type;
        int64_t m_Send_timestamp;
        utility::string_t m_User_id;
    bool m_User_idIsSet;
};

}
}
}
}

#endif /* DataCollectorNewDeviceRequest_H_ */
