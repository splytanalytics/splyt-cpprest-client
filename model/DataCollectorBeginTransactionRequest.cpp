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



#include "DataCollectorBeginTransactionRequest.h"

namespace io {
namespace knetik {
namespace client {
namespace model {

DataCollectorBeginTransactionRequest::DataCollectorBeginTransactionRequest()
{
    m_Timeout = 0;
    m_TimeoutIsSet = false;
    m_Timeout_mode = U("");
    m_Timeout_modeIsSet = false;
    m_Transaction_id = U("");
    m_Transaction_idIsSet = false;
    m_Category = U("");
}

DataCollectorBeginTransactionRequest::~DataCollectorBeginTransactionRequest()
{
}

void DataCollectorBeginTransactionRequest::validate()
{
    // TODO: implement validation
}

web::json::value DataCollectorBeginTransactionRequest::toJson() const
{
    web::json::value val = this->DataCollectorBaseRequest::toJson();

    if(m_TimeoutIsSet)
    {
        val[U("timeout")] = ModelBase::toJson(m_Timeout);
    }
    if(m_Timeout_modeIsSet)
    {
        val[U("timeout_mode")] = ModelBase::toJson(m_Timeout_mode);
    }
    if(m_Transaction_idIsSet)
    {
        val[U("transaction_id")] = ModelBase::toJson(m_Transaction_id);
    }
    val[U("category")] = ModelBase::toJson(m_Category);

    return val;
}

void DataCollectorBeginTransactionRequest::fromJson(web::json::value& val)
{
    this->DataCollectorBaseRequest::fromJson(val);

    if(val.has_field(U("timeout")))
    {
        setTimeout(ModelBase::int32_tFromJson(val[U("timeout")]));
    }
    if(val.has_field(U("timeout_mode")))
    {
        setTimeoutMode(ModelBase::stringFromJson(val[U("timeout_mode")]));
    }
    if(val.has_field(U("transaction_id")))
    {
        setTransactionId(ModelBase::stringFromJson(val[U("transaction_id")]));
    }
    setCategory(ModelBase::stringFromJson(val[U("category")]));
}

void DataCollectorBeginTransactionRequest::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix[namePrefix.size() - 1] != U('.'))
    {
        namePrefix += U(".");
    }

    if(m_Device_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("device_id"), m_Device_id));
        
    }
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
    if(m_TimeoutIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("timeout"), m_Timeout));
    }
    if(m_Timeout_modeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("timeout_mode"), m_Timeout_mode));
        
    }
    if(m_Transaction_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("transaction_id"), m_Transaction_id));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + U("category"), m_Category));
}

void DataCollectorBeginTransactionRequest::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix[namePrefix.size() - 1] != U('.'))
    {
        namePrefix += U(".");
    }

    if(multipart->hasContent(U("device_id")))
    {
        setDeviceId(ModelBase::stringFromHttpContent(multipart->getContent(U("device_id"))));
    }
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
    if(multipart->hasContent(U("timeout")))
    {
        setTimeout(ModelBase::int32_tFromHttpContent(multipart->getContent(U("timeout"))));
    }
    if(multipart->hasContent(U("timeout_mode")))
    {
        setTimeoutMode(ModelBase::stringFromHttpContent(multipart->getContent(U("timeout_mode"))));
    }
    if(multipart->hasContent(U("transaction_id")))
    {
        setTransactionId(ModelBase::stringFromHttpContent(multipart->getContent(U("transaction_id"))));
    }
    setCategory(ModelBase::stringFromHttpContent(multipart->getContent(U("category"))));
}

int32_t DataCollectorBeginTransactionRequest::getTimeout() const
{
    return m_Timeout;
}


void DataCollectorBeginTransactionRequest::setTimeout(int32_t value)
{
    m_Timeout = value;
    m_TimeoutIsSet = true;
}
bool DataCollectorBeginTransactionRequest::timeoutIsSet() const
{
    return m_TimeoutIsSet;
}

void DataCollectorBeginTransactionRequest::unsetTimeout()
{
    m_TimeoutIsSet = false;
}

utility::string_t DataCollectorBeginTransactionRequest::getTimeoutMode() const
{
    return m_Timeout_mode;
}


void DataCollectorBeginTransactionRequest::setTimeoutMode(utility::string_t value)
{
    m_Timeout_mode = value;
    m_Timeout_modeIsSet = true;
}
bool DataCollectorBeginTransactionRequest::timeoutModeIsSet() const
{
    return m_Timeout_modeIsSet;
}

void DataCollectorBeginTransactionRequest::unsetTimeout_mode()
{
    m_Timeout_modeIsSet = false;
}

utility::string_t DataCollectorBeginTransactionRequest::getTransactionId() const
{
    return m_Transaction_id;
}


void DataCollectorBeginTransactionRequest::setTransactionId(utility::string_t value)
{
    m_Transaction_id = value;
    m_Transaction_idIsSet = true;
}
bool DataCollectorBeginTransactionRequest::transactionIdIsSet() const
{
    return m_Transaction_idIsSet;
}

void DataCollectorBeginTransactionRequest::unsetTransaction_id()
{
    m_Transaction_idIsSet = false;
}

utility::string_t DataCollectorBeginTransactionRequest::getCategory() const
{
    return m_Category;
}


void DataCollectorBeginTransactionRequest::setCategory(utility::string_t value)
{
    m_Category = value;
    
}
}
}
}
}

