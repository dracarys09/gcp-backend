/*
 * Generated by gdbus-codegen 2.52.0. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __BACKEND_INTERFACE_H__
#define __BACKEND_INTERFACE_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.openprinting.PrintBackend */

#define TYPE_PRINT_BACKEND (print_backend_get_type ())
#define PRINT_BACKEND(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_PRINT_BACKEND, PrintBackend))
#define IS_PRINT_BACKEND(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_PRINT_BACKEND))
#define PRINT_BACKEND_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_PRINT_BACKEND, PrintBackendIface))

struct _PrintBackend;
typedef struct _PrintBackend PrintBackend;
typedef struct _PrintBackendIface PrintBackendIface;

struct _PrintBackendIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_activate_backend) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_get_active_jobs_count) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_all_jobs) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gboolean arg_active_only);

  gboolean (*handle_get_all_options) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_backend_name) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_get_default_color) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_get_default_media) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_default_orientation) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_get_default_printer) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_get_default_resolution) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_default_value) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name,
    const gchar *arg_option_name);

  gboolean (*handle_get_page_range) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_get_printer_state) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_quality) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_get_supported_color) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_get_supported_media) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_supported_orientation) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_get_supported_resolution) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_get_supported_values_raw_string) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name,
    const gchar *arg_option_name);

  gboolean (*handle_is_accepting_jobs) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_id);

  gboolean (*handle_ping) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name);

  gboolean (*handle_print_file) (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_printer_name,
    const gchar *arg_file_path_name,
    gint arg_num_settings,
    GVariant *arg_settings);

  void (*printer_added) (
    PrintBackend *object,
    const gchar *arg_printer_id,
    const gchar *arg_printer_name,
    const gchar *arg_printer_info,
    const gchar *arg_printer_location,
    const gchar *arg_printer_make_and_model,
    gboolean arg_printer_is_accepting_jobs,
    const gchar *arg_printer_state,
    const gchar *arg_backend_name);

  void (*printer_removed) (
    PrintBackend *object,
    const gchar *arg_printer_id);

};

GType print_backend_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *print_backend_interface_info (void);
guint print_backend_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void print_backend_complete_get_backend_name (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *backend_name);

void print_backend_complete_activate_backend (
    PrintBackend *object,
    GDBusMethodInvocation *invocation);

void print_backend_complete_get_default_printer (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *printer_id);

void print_backend_complete_get_printer_state (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *state);

void print_backend_complete_is_accepting_jobs (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gboolean is_accepting);

void print_backend_complete_get_all_options (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_options,
    GVariant *options);

void print_backend_complete_get_active_jobs_count (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint job_count);

void print_backend_complete_get_all_jobs (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_jobs,
    GVariant *jobs);

void print_backend_complete_print_file (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint jobid);

void print_backend_complete_get_default_media (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *media_name);

void print_backend_complete_get_supported_media (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_values,
    GVariant *values);

void print_backend_complete_get_default_orientation (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *orientation);

void print_backend_complete_get_supported_orientation (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_values,
    GVariant *values);

void print_backend_complete_get_default_resolution (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *resolution);

void print_backend_complete_get_supported_resolution (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_values,
    GVariant *values);

void print_backend_complete_get_default_color (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *color_mode);

void print_backend_complete_get_supported_color (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_values,
    GVariant *values);

void print_backend_complete_ping (
    PrintBackend *object,
    GDBusMethodInvocation *invocation);

void print_backend_complete_get_default_value (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *option_value);

void print_backend_complete_get_supported_values_raw_string (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    gint num_values,
    GVariant *option_values);

void print_backend_complete_get_page_range (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    GVariant *ranges);

void print_backend_complete_get_quality (
    PrintBackend *object,
    GDBusMethodInvocation *invocation,
    const gchar *quality);



/* D-Bus signal emissions functions: */
void print_backend_emit_printer_added (
    PrintBackend *object,
    const gchar *arg_printer_id,
    const gchar *arg_printer_name,
    const gchar *arg_printer_info,
    const gchar *arg_printer_location,
    const gchar *arg_printer_make_and_model,
    gboolean arg_printer_is_accepting_jobs,
    const gchar *arg_printer_state,
    const gchar *arg_backend_name);

void print_backend_emit_printer_removed (
    PrintBackend *object,
    const gchar *arg_printer_id);



/* D-Bus method calls: */
void print_backend_call_get_backend_name (
    PrintBackend *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_backend_name_finish (
    PrintBackend *proxy,
    gchar **out_backend_name,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_backend_name_sync (
    PrintBackend *proxy,
    gchar **out_backend_name,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_activate_backend (
    PrintBackend *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_activate_backend_finish (
    PrintBackend *proxy,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_activate_backend_sync (
    PrintBackend *proxy,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_default_printer (
    PrintBackend *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_default_printer_finish (
    PrintBackend *proxy,
    gchar **out_printer_id,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_default_printer_sync (
    PrintBackend *proxy,
    gchar **out_printer_id,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_printer_state (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_printer_state_finish (
    PrintBackend *proxy,
    gchar **out_state,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_printer_state_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gchar **out_state,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_is_accepting_jobs (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_is_accepting_jobs_finish (
    PrintBackend *proxy,
    gboolean *out_is_accepting,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_is_accepting_jobs_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gboolean *out_is_accepting,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_all_options (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_all_options_finish (
    PrintBackend *proxy,
    gint *out_num_options,
    GVariant **out_options,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_all_options_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gint *out_num_options,
    GVariant **out_options,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_active_jobs_count (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_active_jobs_count_finish (
    PrintBackend *proxy,
    gint *out_job_count,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_active_jobs_count_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gint *out_job_count,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_all_jobs (
    PrintBackend *proxy,
    gboolean arg_active_only,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_all_jobs_finish (
    PrintBackend *proxy,
    gint *out_num_jobs,
    GVariant **out_jobs,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_all_jobs_sync (
    PrintBackend *proxy,
    gboolean arg_active_only,
    gint *out_num_jobs,
    GVariant **out_jobs,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_print_file (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    const gchar *arg_file_path_name,
    gint arg_num_settings,
    GVariant *arg_settings,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_print_file_finish (
    PrintBackend *proxy,
    gint *out_jobid,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_print_file_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    const gchar *arg_file_path_name,
    gint arg_num_settings,
    GVariant *arg_settings,
    gint *out_jobid,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_default_media (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_default_media_finish (
    PrintBackend *proxy,
    gchar **out_media_name,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_default_media_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gchar **out_media_name,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_supported_media (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_supported_media_finish (
    PrintBackend *proxy,
    gint *out_num_values,
    GVariant **out_values,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_supported_media_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gint *out_num_values,
    GVariant **out_values,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_default_orientation (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_default_orientation_finish (
    PrintBackend *proxy,
    gchar **out_orientation,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_default_orientation_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    gchar **out_orientation,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_supported_orientation (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_supported_orientation_finish (
    PrintBackend *proxy,
    gint *out_num_values,
    GVariant **out_values,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_supported_orientation_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    gint *out_num_values,
    GVariant **out_values,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_default_resolution (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_default_resolution_finish (
    PrintBackend *proxy,
    gchar **out_resolution,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_default_resolution_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gchar **out_resolution,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_supported_resolution (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_supported_resolution_finish (
    PrintBackend *proxy,
    gint *out_num_values,
    GVariant **out_values,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_supported_resolution_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_id,
    gint *out_num_values,
    GVariant **out_values,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_default_color (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_default_color_finish (
    PrintBackend *proxy,
    gchar **out_color_mode,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_default_color_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    gchar **out_color_mode,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_supported_color (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_supported_color_finish (
    PrintBackend *proxy,
    gint *out_num_values,
    GVariant **out_values,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_supported_color_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    gint *out_num_values,
    GVariant **out_values,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_ping (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_ping_finish (
    PrintBackend *proxy,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_ping_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_default_value (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    const gchar *arg_option_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_default_value_finish (
    PrintBackend *proxy,
    gchar **out_option_value,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_default_value_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    const gchar *arg_option_name,
    gchar **out_option_value,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_supported_values_raw_string (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    const gchar *arg_option_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_supported_values_raw_string_finish (
    PrintBackend *proxy,
    gint *out_num_values,
    GVariant **out_option_values,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_supported_values_raw_string_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    const gchar *arg_option_name,
    gint *out_num_values,
    GVariant **out_option_values,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_page_range (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_page_range_finish (
    PrintBackend *proxy,
    GVariant **out_ranges,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_page_range_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GVariant **out_ranges,
    GCancellable *cancellable,
    GError **error);

void print_backend_call_get_quality (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean print_backend_call_get_quality_finish (
    PrintBackend *proxy,
    gchar **out_quality,
    GAsyncResult *res,
    GError **error);

gboolean print_backend_call_get_quality_sync (
    PrintBackend *proxy,
    const gchar *arg_printer_name,
    gchar **out_quality,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TYPE_PRINT_BACKEND_PROXY (print_backend_proxy_get_type ())
#define PRINT_BACKEND_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_PRINT_BACKEND_PROXY, PrintBackendProxy))
#define PRINT_BACKEND_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_PRINT_BACKEND_PROXY, PrintBackendProxyClass))
#define PRINT_BACKEND_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_PRINT_BACKEND_PROXY, PrintBackendProxyClass))
#define IS_PRINT_BACKEND_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_PRINT_BACKEND_PROXY))
#define IS_PRINT_BACKEND_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_PRINT_BACKEND_PROXY))

typedef struct _PrintBackendProxy PrintBackendProxy;
typedef struct _PrintBackendProxyClass PrintBackendProxyClass;
typedef struct _PrintBackendProxyPrivate PrintBackendProxyPrivate;

struct _PrintBackendProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  PrintBackendProxyPrivate *priv;
};

struct _PrintBackendProxyClass
{
  GDBusProxyClass parent_class;
};

GType print_backend_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (PrintBackendProxy, g_object_unref)
#endif

void print_backend_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
PrintBackend *print_backend_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
PrintBackend *print_backend_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void print_backend_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
PrintBackend *print_backend_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
PrintBackend *print_backend_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_PRINT_BACKEND_SKELETON (print_backend_skeleton_get_type ())
#define PRINT_BACKEND_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_PRINT_BACKEND_SKELETON, PrintBackendSkeleton))
#define PRINT_BACKEND_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_PRINT_BACKEND_SKELETON, PrintBackendSkeletonClass))
#define PRINT_BACKEND_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_PRINT_BACKEND_SKELETON, PrintBackendSkeletonClass))
#define IS_PRINT_BACKEND_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_PRINT_BACKEND_SKELETON))
#define IS_PRINT_BACKEND_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_PRINT_BACKEND_SKELETON))

typedef struct _PrintBackendSkeleton PrintBackendSkeleton;
typedef struct _PrintBackendSkeletonClass PrintBackendSkeletonClass;
typedef struct _PrintBackendSkeletonPrivate PrintBackendSkeletonPrivate;

struct _PrintBackendSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  PrintBackendSkeletonPrivate *priv;
};

struct _PrintBackendSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType print_backend_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (PrintBackendSkeleton, g_object_unref)
#endif

PrintBackend *print_backend_skeleton_new (void);


G_END_DECLS

#endif /* __BACKEND_INTERFACE_H__ */
