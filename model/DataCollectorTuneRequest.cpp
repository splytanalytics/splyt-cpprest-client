/**
 * Knetik.io Data Collector REST API
 * <p>Use this API to send application data to Knetik.io including user/device information and transactional events.</p> <p>   Please consult the <a href=\"/doc\">official user documentation</a> to find out how to send data, and how this data is used. <p></p> <h2>Notes</h2> <br> New more ReSTful implementation of the telemetry data collection service. Legacy clients can still use the old API format, but we strongly recommend switching over to this new format. Navigate to the legacy documentation using the dropdown at the top of this page. <p></p> <h2>User IDs and Device IDs</h2> <br> Knetik.io can uniquely associate state, events and transactions to users and/or devices for your application. In order to accomplish this, each API call takes userId and deviceId as parameters in the request object. At least one of these must be provided in the request object, except as explicitly noted. <br> <p></p> <h2>Timestamps</h2> <br> All timestamp parameters must be epoch timestamps in milliseconds. <br> <p></p> <h2>Required Request Headers</h2> <br> The following HTTP header values must be provided for each API call: <ul>   <li>     <b>Content-Type: application/json</b>   </li> </ul> <p></p> <h2>Required Query Parameters</h2> <br> All API calls also require the following query parameters to be present on the URL: <ul>   <li>     <b>customer_id:</b> your unique customer ID   </li> </ul> <p></p> <h2>API Responses</h2> <br> If successful, API calls will simply return an HTTP response code of ACCEPTED (202) with no other data. If errors occur, a JSON payload will be returned containing detailed error information and an appropriate HTTP error status code will be provided (as documented in each of the API methods). <br> <p></p>
 *
 * OpenAPI spec version: 2.0
 * Contact: support@knetik.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */



#include "DataCollectorTuneRequest.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

DataCollectorTuneRequest::DataCollectorTuneRequest()
{
    m_Campaign_name = U("");
    m_Device_id = U("");
    m_Event_propertiesIsSet = false;
    m_Event_timestamp = 0;
    m_Request_type = U("");
    m_Send_timestamp = 0;
    m_User_id = U("");
    m_User_idIsSet = false;
    
}

DataCollectorTuneRequest::~DataCollectorTuneRequest()
{
}

void DataCollectorTuneRequest::validate()
{
    // TODO: implement validation
}

web::json::value DataCollectorTuneRequest::toJson() const
{
    web::json::value val = web::json::value::object();

    val[U("campaign_name")] = ModelBase::toJson(m_Campaign_name);
    val[U("device_id")] = ModelBase::toJson(m_Device_id);
    if(m_Event_propertiesIsSet)
    {
        val[U("event_properties")] = ModelBase::toJson(m_Event_properties);
    }
    val[U("event_timestamp")] = ModelBase::toJson(m_Event_timestamp);
    val[U("request_type")] = ModelBase::toJson(m_Request_type);
    val[U("send_timestamp")] = ModelBase::toJson(m_Send_timestamp);
    if(m_User_idIsSet)
    {
        val[U("user_id")] = ModelBase::toJson(m_User_id);
    }
    

    return val;
}

void DataCollectorTuneRequest::fromJson(web::json::value& val)
{
    setCampaignName(ModelBase::stringFromJson(val[U("campaign_name")]));
    setDeviceId(ModelBase::stringFromJson(val[U("device_id")]));
    if(val.has_field(U("event_properties")))
    {
        if(!val[U("event_properties")].is_null())
        {
            std::shared_ptr<Object> newItem(nullptr);
            newItem->fromJson(val[U("event_properties")]);
            setEventProperties( newItem );
        }
        
    }
    setEventTimestamp(ModelBase::int64_tFromJson(val[U("event_timestamp")]));
    setRequestType(ModelBase::stringFromJson(val[U("request_type")]));
    setSendTimestamp(ModelBase::int64_tFromJson(val[U("send_timestamp")]));
    if(val.has_field(U("user_id")))
    {
        setUserId(ModelBase::stringFromJson(val[U("user_id")]));
        
    }
    
}

void DataCollectorTuneRequest::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix[namePrefix.size() - 1] != U('.'))
    {
        namePrefix += U(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + U("campaign_name"), m_Campaign_name));
    multipart->add(ModelBase::toHttpContent(namePrefix + U("device_id"), m_Device_id));
    if(m_Event_propertiesIsSet)
    {
        if (m_Event_properties.get())
        {
            m_Event_properties->toMultipart(multipart, U("event_properties."));
        }
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + U("event_timestamp"), m_Event_timestamp));
    multipart->add(ModelBase::toHttpContent(namePrefix + U("request_type"), m_Request_type));
    multipart->add(ModelBase::toHttpContent(namePrefix + U("send_timestamp"), m_Send_timestamp));
    if(m_User_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("user_id"), m_User_id));
        
    }
    
}

void DataCollectorTuneRequest::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix[namePrefix.size() - 1] != U('.'))
    {
        namePrefix += U(".");
    }

    setCampaignName(ModelBase::stringFromHttpContent(multipart->getContent(U("campaign_name"))));
    setDeviceId(ModelBase::stringFromHttpContent(multipart->getContent(U("device_id"))));
    if(multipart->hasContent(U("event_properties")))
    {
        if(multipart->hasContent(U("event_properties")))
        {
            std::shared_ptr<Object> newItem(nullptr);
            newItem->fromMultiPart(multipart, U("event_properties."));
            setEventProperties( newItem );
        }
        
    }
    setEventTimestamp(ModelBase::int64_tFromHttpContent(multipart->getContent(U("event_timestamp"))));
    setRequestType(ModelBase::stringFromHttpContent(multipart->getContent(U("request_type"))));
    setSendTimestamp(ModelBase::int64_tFromHttpContent(multipart->getContent(U("send_timestamp"))));
    if(multipart->hasContent(U("user_id")))
    {
        setUserId(ModelBase::stringFromHttpContent(multipart->getContent(U("user_id"))));
        
    }
    
}


utility::string_t DataCollectorTuneRequest::getCampaignName() const
{
    return m_Campaign_name;
}
void DataCollectorTuneRequest::setCampaignName(utility::string_t value)
{
    m_Campaign_name = value;
    
}
utility::string_t DataCollectorTuneRequest::getDeviceId() const
{
    return m_Device_id;
}
void DataCollectorTuneRequest::setDeviceId(utility::string_t value)
{
    m_Device_id = value;
    
}
std::shared_ptr<Object> DataCollectorTuneRequest::getEventProperties() const
{
    return m_Event_properties;
}
void DataCollectorTuneRequest::setEventProperties(std::shared_ptr<Object> value)
{
    m_Event_properties = value;
    m_Event_propertiesIsSet = true;
}
bool DataCollectorTuneRequest::event_propertiesIsSet() const
{
    return m_Event_propertiesIsSet;
}
void DataCollectorTuneRequest::unsetEvent_properties()
{
    m_Event_propertiesIsSet = false;
}
int64_t DataCollectorTuneRequest::getEventTimestamp() const
{
    return m_Event_timestamp;
}
void DataCollectorTuneRequest::setEventTimestamp(int64_t value)
{
    m_Event_timestamp = value;
    
}
utility::string_t DataCollectorTuneRequest::getRequestType() const
{
    return m_Request_type;
}
void DataCollectorTuneRequest::setRequestType(utility::string_t value)
{
    m_Request_type = value;
    
}
int64_t DataCollectorTuneRequest::getSendTimestamp() const
{
    return m_Send_timestamp;
}
void DataCollectorTuneRequest::setSendTimestamp(int64_t value)
{
    m_Send_timestamp = value;
    
}
utility::string_t DataCollectorTuneRequest::getUserId() const
{
    return m_User_id;
}
void DataCollectorTuneRequest::setUserId(utility::string_t value)
{
    m_User_id = value;
    m_User_idIsSet = true;
}
bool DataCollectorTuneRequest::user_idIsSet() const
{
    return m_User_idIsSet;
}
void DataCollectorTuneRequest::unsetUser_id()
{
    m_User_idIsSet = false;
}

}
}
}
}

