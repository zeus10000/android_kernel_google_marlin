#ifndef _UAPI_LINUX_DEVLINK_H_
#define _UAPI_LINUX_DEVLINK_H_
#define DEVLINK_GENL_NAME "devlink"
#define DEVLINK_GENL_VERSION 1
enum devlink_command { DEVLINK_CMD_UNSPEC, __DEVLINK_CMD_MAX };
enum devlink_attr { DEVLINK_ATTR_UNSPEC, __DEVLINK_ATTR_MAX };
enum devlink_port_type { DEVLINK_PORT_TYPE_NOTSET, DEVLINK_PORT_TYPE_AUTO, DEVLINK_PORT_TYPE_ETH, DEVLINK_PORT_TYPE_IB };
enum devlink_port_flavour { DEVLINK_PORT_FLAVOUR_PHYSICAL };
enum devlink_sb_pool_type { DEVLINK_SB_POOL_TYPE_INGRESS, DEVLINK_SB_POOL_TYPE_EGRESS };
enum devlink_sb_threshold_type { DEVLINK_SB_THRESHOLD_TYPE_STATIC, DEVLINK_SB_THRESHOLD_TYPE_DYNAMIC };
enum devlink_eswitch_mode { DEVLINK_ESWITCH_MODE_LEGACY, DEVLINK_ESWITCH_MODE_SWITCHDEV };
enum devlink_eswitch_inline_mode { DEVLINK_ESWITCH_INLINE_MODE_NONE };
enum devlink_eswitch_encap_mode { DEVLINK_ESWITCH_ENCAP_MODE_NONE };
enum devlink_param_cmode { DEVLINK_PARAM_CMODE_RUNTIME };
enum devlink_resource_unit { DEVLINK_RESOURCE_UNIT_ENTRY };
#endif
