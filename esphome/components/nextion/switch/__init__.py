import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch

from esphome.const import CONF_ID
from .. import nextion_ns, CONF_NEXTION_ID

from ..base_component import (
    setup_component_core_,
    CONF_COMPONENT_NAME,
    CONF_VARIABLE_NAME,
    CONFIG_SWITCH_COMPONENT_SCHEMA,
)

CODEOWNERS = ["@senexcrenshaw"]
DEPENDENCIES = ["display"]

NextionSwitch = nextion_ns.class_("NextionSwitch", switch.Switch, cg.PollingComponent)

CONFIG_SCHEMA = cv.All(
    switch.SWITCH_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(NextionSwitch),
        }
    )
    .extend(CONFIG_SWITCH_COMPONENT_SCHEMA)
    .extend(cv.polling_component_schema("never")),
    cv.has_exactly_one_key(CONF_COMPONENT_NAME, CONF_VARIABLE_NAME),
)


def to_code(config):
    hub = yield cg.get_variable(config[CONF_NEXTION_ID])
    var = cg.new_Pvariable(config[CONF_ID], hub)
    yield cg.register_component(var, config)
    yield switch.register_switch(var, config)

    cg.add(hub.register_switch_component(var))

    yield setup_component_core_(var, config, ".val")
