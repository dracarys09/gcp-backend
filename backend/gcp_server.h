#ifndef __GCP_SERVER_H__
#define __GCP_SERVER_H__

#include <glib.h>
#include <glib-object.h>
#include "gcp.h"

G_BEGIN_DECLS

#define SERVER_TYPE_OBJECT server_object_get_type()
G_DECLARE_DERIVABLE_TYPE (ServerObject, server_object, Server, OBJECT, GObject)

struct _ServerObjectClass
{
  GObjectClass parent;
};

ServerObject *
server_object_new ();

static void
acquire_session_bus_name ();

static void
on_name_acquired (GDBusConnection *connection,
                  const gchar *name,
                  gpointer user_data);

static gboolean
on_handle_get_printers (PrintBackend *skeleton,
                        GDBusMethodInvocation *invocation,
                        const gchar *access_token,
                        const gchar *connection_status,
                        gpointer user_data);

static gboolean
on_handle_get_printer_options (PrintBackend *skeleton,
                               GDBusMethodInvocation *invocation,
                               const gchar *uid,
                               const gchar *access_token,
                               gpointer user_data);

static gboolean
on_handle_submit_print_job (PrintBackend *skeleton,
                            GDBusMethodInvocation *invocation,
                            const gchar *uid,
                            const gchar *access_token,
                            const gchar *title,
                            const gchar *ticket,
                            gpointer user_data);

static gboolean
on_handle_get_print_jobs   (PrintBackend *skeleton,
                            GDBusMethodInvocation *invocation,
                            const gchar *access_token,
                            const gchar *uid,
                            const gchar *owner,
                            const gchar *status,
                            const gchar *sortorder,
                            gpointer user_data);

void connect_to_signals (PrintBackend *skeleton);


G_END_DECLS

#endif