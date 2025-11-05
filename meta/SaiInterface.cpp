#include "SaiInterface.h"
#include "sai_serialize.h"
#include "swss/logger.h"

using namespace sairedis;

sai_status_t SaiInterface::create(
        _Inout_ sai_object_meta_key_t& metaKey,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    auto info = sai_metadata_get_object_type_info(metaKey.objecttype);

    if (!info)
    {
        SWSS_LOG_ERROR("invalid object type: %d", metaKey.objecttype);

        return SAI_STATUS_FAILURE;
    }
    sai_status_t status = SAI_STATUS_NOT_EXECUTED;
    SWSS_LOG_DEBUG("SAIInterface::create start: %s", sai_serialize_object_type(metaKey.objecttype).c_str());
    if (info->isobjectid)
    {
        status = create(metaKey.objecttype, &metaKey.objectkey.key.object_id, switch_id, attr_count, attr_list);
    }
    else {
        switch ((int)info->objecttype)
        {
            case SAI_OBJECT_TYPE_FDB_ENTRY:
                status = create(&metaKey.objectkey.key.fdb_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_ROUTE_ENTRY:
                status = create(&metaKey.objectkey.key.route_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_NEIGHBOR_ENTRY:
                status = create(&metaKey.objectkey.key.neighbor_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_NAT_ENTRY:
                status = create(&metaKey.objectkey.key.nat_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_INSEG_ENTRY:
                status = create(&metaKey.objectkey.key.inseg_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_MY_SID_ENTRY:
                status = create(&metaKey.objectkey.key.my_sid_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_DIRECTION_LOOKUP_ENTRY:
                status = create(&metaKey.objectkey.key.direction_lookup_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_ENI_ETHER_ADDRESS_MAP_ENTRY:
                status = create(&metaKey.objectkey.key.eni_ether_address_map_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_VIP_ENTRY:
                status = create(&metaKey.objectkey.key.vip_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_INBOUND_ROUTING_ENTRY:
                status = create(&metaKey.objectkey.key.inbound_routing_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_PA_VALIDATION_ENTRY:
                status = create(&metaKey.objectkey.key.pa_validation_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_ROUTING_ENTRY:
                status = create(&metaKey.objectkey.key.outbound_routing_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_CA_TO_PA_ENTRY:
                status = create(&metaKey.objectkey.key.outbound_ca_to_pa_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_PORT_MAP_PORT_RANGE_ENTRY:
                status = create(&metaKey.objectkey.key.outbound_port_map_port_range_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_GLOBAL_TRUSTED_VNI_ENTRY:
                status = create(&metaKey.objectkey.key.global_trusted_vni_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_ENI_TRUSTED_VNI_ENTRY:
                status = create(&metaKey.objectkey.key.eni_trusted_vni_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_IPMC_ENTRY:
                status = create(&metaKey.objectkey.key.ipmc_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_L2MC_ENTRY:
                status = create(&metaKey.objectkey.key.l2mc_entry, attr_count, attr_list);
                break;

            default:

                SWSS_LOG_ERROR("object type %s not implemented, FIXME", info->objecttypename);

                return SAI_STATUS_FAILURE;
        }

    }

    SWSS_LOG_DEBUG("SAIInterface::create end: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    return status;
}

sai_status_t SaiInterface::remove(
        _In_ const sai_object_meta_key_t& metaKey)
{
    SWSS_LOG_ENTER();

    auto info = sai_metadata_get_object_type_info(metaKey.objecttype);

    if (!info)
    {
        SWSS_LOG_ERROR("invalid object type: %d", metaKey.objecttype);

        return SAI_STATUS_FAILURE;
    }
    sai_status_t status = SAI_STATUS_NOT_EXECUTED;
    SWSS_LOG_DEBUG("SAIInterface::remove start: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    if (info->isobjectid)
    {
        status = remove(metaKey.objecttype, metaKey.objectkey.key.object_id);
    }
    else {
        switch ((int)info->objecttype)
        {
            case SAI_OBJECT_TYPE_FDB_ENTRY:
                status = remove(&metaKey.objectkey.key.fdb_entry);
                break;

            case SAI_OBJECT_TYPE_ROUTE_ENTRY:
                status = remove(&metaKey.objectkey.key.route_entry);
                break;

            case SAI_OBJECT_TYPE_NEIGHBOR_ENTRY:
                status = remove(&metaKey.objectkey.key.neighbor_entry);
                break;

            case SAI_OBJECT_TYPE_NAT_ENTRY:
                status = remove(&metaKey.objectkey.key.nat_entry);
                break;

            case SAI_OBJECT_TYPE_INSEG_ENTRY:
                status = remove(&metaKey.objectkey.key.inseg_entry);
                break;

            case SAI_OBJECT_TYPE_MY_SID_ENTRY:
                status = remove(&metaKey.objectkey.key.my_sid_entry);
                break;

            case SAI_OBJECT_TYPE_DIRECTION_LOOKUP_ENTRY:
                status = remove(&metaKey.objectkey.key.direction_lookup_entry);
                break;

            case SAI_OBJECT_TYPE_ENI_ETHER_ADDRESS_MAP_ENTRY:
                status = remove(&metaKey.objectkey.key.eni_ether_address_map_entry);
                break;

            case SAI_OBJECT_TYPE_VIP_ENTRY:
                status = remove(&metaKey.objectkey.key.vip_entry);
                break;

            case SAI_OBJECT_TYPE_INBOUND_ROUTING_ENTRY:
                status = remove(&metaKey.objectkey.key.inbound_routing_entry);
                break;

            case SAI_OBJECT_TYPE_PA_VALIDATION_ENTRY:
                status = remove(&metaKey.objectkey.key.pa_validation_entry);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_ROUTING_ENTRY:
                status = remove(&metaKey.objectkey.key.outbound_routing_entry);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_CA_TO_PA_ENTRY:
                status = remove(&metaKey.objectkey.key.outbound_ca_to_pa_entry);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_PORT_MAP_PORT_RANGE_ENTRY:
                status = remove(&metaKey.objectkey.key.outbound_port_map_port_range_entry);
                break;

            case SAI_OBJECT_TYPE_GLOBAL_TRUSTED_VNI_ENTRY:
                status = remove(&metaKey.objectkey.key.global_trusted_vni_entry);
                break;

            case SAI_OBJECT_TYPE_ENI_TRUSTED_VNI_ENTRY:
                status = remove(&metaKey.objectkey.key.eni_trusted_vni_entry);
                break;

            case SAI_OBJECT_TYPE_IPMC_ENTRY:
                status = remove(&metaKey.objectkey.key.ipmc_entry);
                break;

            case SAI_OBJECT_TYPE_L2MC_ENTRY:
                status = remove(&metaKey.objectkey.key.l2mc_entry);
                break;

            default:

                SWSS_LOG_ERROR("object type %s not implemented, FIXME", info->objecttypename);

                return SAI_STATUS_FAILURE;
        }

    }

    SWSS_LOG_DEBUG("SAIInterface::remove end: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    return status;
}

sai_status_t SaiInterface::set(
        _In_ const sai_object_meta_key_t& metaKey,
        _In_ const sai_attribute_t *attr)
{
    SWSS_LOG_ENTER();

    auto info = sai_metadata_get_object_type_info(metaKey.objecttype);

    if (!info)
    {
        SWSS_LOG_ERROR("invalid object type: %d", metaKey.objecttype);

        return SAI_STATUS_FAILURE;
    }
    sai_status_t status = SAI_STATUS_NOT_EXECUTED;
    SWSS_LOG_DEBUG("SAIInterface::set start: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    if (info->isobjectid)
    {
        status = set(metaKey.objecttype, metaKey.objectkey.key.object_id, attr);
    }
    else {
        switch ((int)info->objecttype)
        {
            case SAI_OBJECT_TYPE_FDB_ENTRY:
                status = set(&metaKey.objectkey.key.fdb_entry, attr);
                break;

            case SAI_OBJECT_TYPE_ROUTE_ENTRY:
                status = set(&metaKey.objectkey.key.route_entry, attr);
                break;

            case SAI_OBJECT_TYPE_NEIGHBOR_ENTRY:
                status = set(&metaKey.objectkey.key.neighbor_entry, attr);
                break;

            case SAI_OBJECT_TYPE_NAT_ENTRY:
                status = set(&metaKey.objectkey.key.nat_entry, attr);
                break;

            case SAI_OBJECT_TYPE_INSEG_ENTRY:
                status = set(&metaKey.objectkey.key.inseg_entry, attr);
                break;

            case SAI_OBJECT_TYPE_MY_SID_ENTRY:
                status = set(&metaKey.objectkey.key.my_sid_entry, attr);
                break;

            case SAI_OBJECT_TYPE_DIRECTION_LOOKUP_ENTRY:
                status = set(&metaKey.objectkey.key.direction_lookup_entry, attr);
                break;

            case SAI_OBJECT_TYPE_ENI_ETHER_ADDRESS_MAP_ENTRY:
                status = set(&metaKey.objectkey.key.eni_ether_address_map_entry, attr);
                break;

            case SAI_OBJECT_TYPE_VIP_ENTRY:
                status = set(&metaKey.objectkey.key.vip_entry, attr);
                break;

            case SAI_OBJECT_TYPE_INBOUND_ROUTING_ENTRY:
                status = set(&metaKey.objectkey.key.inbound_routing_entry, attr);
                break;

            case SAI_OBJECT_TYPE_PA_VALIDATION_ENTRY:
                status = set(&metaKey.objectkey.key.pa_validation_entry, attr);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_ROUTING_ENTRY:
                status = set(&metaKey.objectkey.key.outbound_routing_entry, attr);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_CA_TO_PA_ENTRY:
                status = set(&metaKey.objectkey.key.outbound_ca_to_pa_entry, attr);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_PORT_MAP_PORT_RANGE_ENTRY:
                status = set(&metaKey.objectkey.key.outbound_port_map_port_range_entry, attr);
                break;

            case SAI_OBJECT_TYPE_GLOBAL_TRUSTED_VNI_ENTRY:
                status = set(&metaKey.objectkey.key.global_trusted_vni_entry, attr);
                break;

            case SAI_OBJECT_TYPE_ENI_TRUSTED_VNI_ENTRY:
                status = set(&metaKey.objectkey.key.eni_trusted_vni_entry, attr);
                break;

            case SAI_OBJECT_TYPE_IPMC_ENTRY:
                status = set(&metaKey.objectkey.key.ipmc_entry, attr);
                break;

            case SAI_OBJECT_TYPE_L2MC_ENTRY:
                status = set(&metaKey.objectkey.key.l2mc_entry, attr);
                break;

            default:

                SWSS_LOG_ERROR("object type %s not implemented, FIXME", info->objecttypename);

                return SAI_STATUS_FAILURE;
        }

    }

    SWSS_LOG_DEBUG("SAIInterface::set end: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    return status;
}

sai_status_t SaiInterface::get(
        _In_ const sai_object_meta_key_t& metaKey,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
    SWSS_LOG_ENTER();

    auto info = sai_metadata_get_object_type_info(metaKey.objecttype);

    if (!info)
    {
        SWSS_LOG_ERROR("invalid object type: %d", metaKey.objecttype);

        return SAI_STATUS_FAILURE;
    }
    sai_status_t status = SAI_STATUS_NOT_EXECUTED;
    SWSS_LOG_DEBUG("SAIInterface::get start: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    if (info->isobjectid)
    {
        status = get(metaKey.objecttype, metaKey.objectkey.key.object_id, attr_count, attr_list);
    }
    else {
        switch ((int)info->objecttype)
        {
            case SAI_OBJECT_TYPE_FDB_ENTRY:
                status = get(&metaKey.objectkey.key.fdb_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_ROUTE_ENTRY:
                status = get(&metaKey.objectkey.key.route_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_NEIGHBOR_ENTRY:
                status = get(&metaKey.objectkey.key.neighbor_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_NAT_ENTRY:
                status = get(&metaKey.objectkey.key.nat_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_INSEG_ENTRY:
                status = get(&metaKey.objectkey.key.inseg_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_MY_SID_ENTRY:
                status = get(&metaKey.objectkey.key.my_sid_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_DIRECTION_LOOKUP_ENTRY:
                status = get(&metaKey.objectkey.key.direction_lookup_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_ENI_ETHER_ADDRESS_MAP_ENTRY:
                status = get(&metaKey.objectkey.key.eni_ether_address_map_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_VIP_ENTRY:
                status = get(&metaKey.objectkey.key.vip_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_INBOUND_ROUTING_ENTRY:
                status = get(&metaKey.objectkey.key.inbound_routing_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_PA_VALIDATION_ENTRY:
                status = get(&metaKey.objectkey.key.pa_validation_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_ROUTING_ENTRY:
                status = get(&metaKey.objectkey.key.outbound_routing_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_CA_TO_PA_ENTRY:
                status = get(&metaKey.objectkey.key.outbound_ca_to_pa_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_OUTBOUND_PORT_MAP_PORT_RANGE_ENTRY:
                status = get(&metaKey.objectkey.key.outbound_port_map_port_range_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_GLOBAL_TRUSTED_VNI_ENTRY:
                status = get(&metaKey.objectkey.key.global_trusted_vni_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_ENI_TRUSTED_VNI_ENTRY:
                status = get(&metaKey.objectkey.key.eni_trusted_vni_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_IPMC_ENTRY:
                status = get(&metaKey.objectkey.key.ipmc_entry, attr_count, attr_list);
                break;

            case SAI_OBJECT_TYPE_L2MC_ENTRY:
                status = get(&metaKey.objectkey.key.l2mc_entry, attr_count, attr_list);
                break;

            default:

                SWSS_LOG_ERROR("object type %s not implemented, FIXME", info->objecttypename);

                return SAI_STATUS_FAILURE;
        }
    }

    SWSS_LOG_DEBUG("SAIInterface::get end: %s", sai_serialize_object_type(metaKey.objecttype).c_str());

    return status;
}

sai_status_t SaiInterface::switchMdioRead(
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t device_addr,
        _In_ uint32_t start_reg_addr,
        _In_ uint32_t number_of_registers,
        _Out_ uint32_t *reg_val)
{
    SWSS_LOG_ENTER();

    return SAI_STATUS_FAILURE;
}

sai_status_t SaiInterface::switchMdioWrite(
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t device_addr,
        _In_ uint32_t start_reg_addr,
        _In_ uint32_t number_of_registers,
        _In_ const uint32_t *reg_val)
{
    SWSS_LOG_ENTER();

    return SAI_STATUS_FAILURE;
}

sai_status_t SaiInterface::switchMdioCl22Read(
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t device_addr,
        _In_ uint32_t start_reg_addr,
        _In_ uint32_t number_of_registers,
        _Out_ uint32_t *reg_val)
{
    SWSS_LOG_ENTER();

    return SAI_STATUS_FAILURE;
}

sai_status_t SaiInterface::switchMdioCl22Write(
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t device_addr,
        _In_ uint32_t start_reg_addr,
        _In_ uint32_t number_of_registers,
        _In_ const uint32_t *reg_val)
{
    SWSS_LOG_ENTER();

    return SAI_STATUS_FAILURE;
}

sai_log_level_t SaiInterface::logGet(
        _In_ sai_api_t api)
{
    SWSS_LOG_ENTER();

    // default for all apis

    return SAI_LOG_LEVEL_NOTICE;
}

sai_status_t SaiInterface::getStats(
        _In_ const sai_meter_bucket_entry_t* entry,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters)
{
    SWSS_LOG_ENTER();

    SWSS_LOG_ERROR("not implemented");

    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t SaiInterface::getStatsExt(
        _In_ const sai_meter_bucket_entry_t* entry,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters)
{
    SWSS_LOG_ENTER();

    SWSS_LOG_ERROR("not implemented");

    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t SaiInterface::clearStats(
        _In_ const sai_meter_bucket_entry_t* entry,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids)
{
    SWSS_LOG_ENTER();

    SWSS_LOG_ERROR("not implemented");

    return SAI_STATUS_NOT_IMPLEMENTED;
}

std::shared_ptr<SaiOptions> SaiInterface::getOptions(
        _In_ const std::string& key)
{
    SWSS_LOG_ENTER();

    return m_optionsMap[key];
}

void SaiInterface::setOptions(
        _In_ const std::string& key,
        _In_ std::shared_ptr<SaiOptions> options)
{
    SWSS_LOG_ENTER();

    m_optionsMap[key] = options;
}
