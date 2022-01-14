/***************************************************************************//**
 * @file sl_cli_command_table.c
 * @brief Declarations of relevant command structs for cli framework.
 * @version x.y.z
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include <stdlib.h>

#include "sl_cli_config.h"
#include "sl_cli_command.h"
#include "sl_cli_arguments.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *****************************   TEMPLATED FILE   ******************************
 ******************************************************************************/

/*******************************************************************************
 * Example syntax (.slcc or .slcp) for populating this file:
 *
 *   template_contribution:
 *     - name: cli_command          # Register a command
 *       value:
 *         name: status             # Name of command
 *         handler: status_command  # Function to be called. Must be defined
 *         help: "Prints status"    # Optional help description
 *         shortcuts:               # Optional shorcut list
 *           - name: st
 *         argument:                # Argument list, if apliccable
 *           - type: uint8          # Variable type
 *             help: "Channel"      # Optional description
 *           - type: string
 *             help: "Text"
 *     - name: cli_group            # Register a group
 *       value:
 *         name: shell              # Group name
 *         help: "Shell commands"   # Optional help description
 *         shortcuts:               # Optional shorcuts
 *           - name: sh
 *     - name: cli_command
 *       value:
 *         name: repeat
 *         handler: repeat_cmd
 *         help: "Repeat commands"
 *         shortcuts:
 *           - name: r
 *           - name: rep
 *         group: shell            # Associate command with group
 *         argument:
 *           - type: string
 *             help: "Text"
 *           - type: additional
 *             help: "More text"
 *
 * For subgroups, an optional unique id can be used to allow a particular name to
 * be used more than once. In the following case, from the command line the
 * following commands are available:
 *
 * >  root_1 shell status
 * >  root_2 shell status
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_1             # Group name
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_2             # Group name
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_1         # Optional unique id for group
 *         group: root_1            # Add group to root_1 group
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_2         # Optional unique id for group
 *         group: root_2            # Add group to root_1 group
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_1
 *         group: shell_root_1      # id of subgroup
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_2
 *         group: shell_root_2      # id of subgroup
 *
 ******************************************************************************/

// Provide function declarations
void cli_active_scan(sl_cli_command_arg_t *arguments);
void cli_commission(sl_cli_command_arg_t *arguments);
void cli_energy_scan(sl_cli_command_arg_t *arguments);
void cli_form(sl_cli_command_arg_t *arguments);
void cli_info(sl_cli_command_arg_t *arguments);
void cli_join_network(sl_cli_command_arg_t *arguments);
void cli_leave(sl_cli_command_arg_t *arguments);
void cli_set_permit_join(sl_cli_command_arg_t *arguments);
void cli_poll(sl_cli_command_arg_t *arguments);
void cli_purge_indirect(sl_cli_command_arg_t *arguments);
void cli_reset(sl_cli_command_arg_t *arguments);
void cli_send(sl_cli_command_arg_t *arguments);
void cli_set_beacon_payload(sl_cli_command_arg_t *arguments);
void cli_set_channel(sl_cli_command_arg_t *arguments);
void cli_set_security_key(sl_cli_command_arg_t *arguments);
void cli_set_options(sl_cli_command_arg_t *arguments);
void cli_set_poll_destination(sl_cli_command_arg_t *arguments);

// Command structs. Names are in the format : cli_cmd_{command group name}_{command name}
// In order to support hyphen in command and group name, every occurence of it while
// building struct names will be replaced by "_hyphen_"
static const sl_cli_command_info_t cli_cmd__active_scan = \
  SL_CLI_COMMAND(cli_active_scan,
                 "Start active scanning on selected channel",
                  "Selected channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__commission = \
  SL_CLI_COMMAND(cli_commission,
                 "Commission node parameters",
                  "Node type" SL_CLI_UNIT_SEPARATOR "Node id" SL_CLI_UNIT_SEPARATOR "Pan id" SL_CLI_UNIT_SEPARATOR "Radio TX power" SL_CLI_UNIT_SEPARATOR "Radio channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_INT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__energy_scan = \
  SL_CLI_COMMAND(cli_energy_scan,
                 "Start energy scanning on the given channel with samples (num)",
                  "Channel to scan" SL_CLI_UNIT_SEPARATOR "Samples" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__form = \
  SL_CLI_COMMAND(cli_form,
                 "Form network",
                  "Pan id" SL_CLI_UNIT_SEPARATOR "Radio TX power" SL_CLI_UNIT_SEPARATOR "Radio channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_INT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__info = \
  SL_CLI_COMMAND(cli_info,
                 "List network and device params",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__join = \
  SL_CLI_COMMAND(cli_join_network,
                 "Start to join network",
                  "Node type" SL_CLI_UNIT_SEPARATOR "Pan id" SL_CLI_UNIT_SEPARATOR "Radio TX power" SL_CLI_UNIT_SEPARATOR "Radio channel" SL_CLI_UNIT_SEPARATOR "Use long addressing" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_INT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__leave = \
  SL_CLI_COMMAND(cli_leave,
                 "Leave current network, resets states",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__pjoin = \
  SL_CLI_COMMAND(cli_set_permit_join,
                 "Permit join set with duration",
                  "Duration" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__poll = \
  SL_CLI_COMMAND(cli_poll,
                 "Get poll status",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__purge_indirect = \
  SL_CLI_COMMAND(cli_purge_indirect,
                 "Indirect purge",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__reset = \
  SL_CLI_COMMAND(cli_reset,
                 "Reset device",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send = \
  SL_CLI_COMMAND(cli_send,
                 "Send message",
                  "MAC frame info" SL_CLI_UNIT_SEPARATOR "Short Source id" SL_CLI_UNIT_SEPARATOR "Source long address" SL_CLI_UNIT_SEPARATOR "Short Destination id" SL_CLI_UNIT_SEPARATOR "Destination long address" SL_CLI_UNIT_SEPARATOR "Source pan id" SL_CLI_UNIT_SEPARATOR "Destination pan id" SL_CLI_UNIT_SEPARATOR "Message" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_beacon_payload = \
  SL_CLI_COMMAND(cli_set_beacon_payload,
                 "Set beacon payload",
                  "Payload" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_channel = \
  SL_CLI_COMMAND(cli_set_channel,
                 "Radio channel set",
                  "Channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_key = \
  SL_CLI_COMMAND(cli_set_security_key,
                 "Set security key",
                  "Channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_options = \
  SL_CLI_COMMAND(cli_set_options,
                 "Set options",
                  "TX options" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_poll_dest = \
  SL_CLI_COMMAND(cli_set_poll_destination,
                 "Set Poll Destination",
                  "Destination short address" SL_CLI_UNIT_SEPARATOR "Destination long address" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });


// Create group command tables and structs if cli_groups given
// in template. Group name is suffixed with _group_table for tables
// and group commands are cli_cmd_grp_( group name )
// Create root command table
const sl_cli_command_entry_t sl_cli_default_command_table[] = {
  { "active_scan", &cli_cmd__active_scan, false },
  { "commission", &cli_cmd__commission, false },
  { "energy_scan", &cli_cmd__energy_scan, false },
  { "form", &cli_cmd__form, false },
  { "info", &cli_cmd__info, false },
  { "join", &cli_cmd__join, false },
  { "leave", &cli_cmd__leave, false },
  { "pjoin", &cli_cmd__pjoin, false },
  { "poll", &cli_cmd__poll, false },
  { "purge_indirect", &cli_cmd__purge_indirect, false },
  { "reset", &cli_cmd__reset, false },
  { "send", &cli_cmd__send, false },
  { "set_beacon_payload", &cli_cmd__set_beacon_payload, false },
  { "set_channel", &cli_cmd__set_channel, false },
  { "set_key", &cli_cmd__set_key, false },
  { "set_options", &cli_cmd__set_options, false },
  { "set_poll_dest", &cli_cmd__set_poll_dest, false },
  { NULL, NULL, false },
};


#ifdef __cplusplus
}
#endif
