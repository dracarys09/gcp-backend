#include "gcp.h"

G_DEFINE_TYPE (GCPObject, gcp_object, G_TYPE_OBJECT)

/*****************************************************************************/
const gchar *
gcp_object_real_get_printers (GCPObject *self,
                              const gchar *access_token,
                              const gchar *connection_status);

const gchar *
gcp_object_real_get_printer_options (GCPObject   *self,
                                     const gchar *uid,
                                     const gchar *access_token);

gboolean
gcp_object_real_submit_print_job (GCPObject   *self,
                                  const gchar *uid,
                                  const gchar *access_token,
                                  const gchar *title,
                                  const gchar *ticket);
/*****************************************************************************/

GCPObject *
gcp_object_new()
{
  return g_object_new (GCP_TYPE_OBJECT, NULL);
}

static void
gcp_object_init (GCPObject *self)
{
}

static void
gcp_object_class_init (GCPObjectClass *klass)
{
  GObjectClass *parent_class = G_OBJECT_CLASS (klass);

  klass->get_printers = gcp_object_real_get_printers;
  klass->get_printer_options = gcp_object_real_get_printer_options;
  klass->submit_print_job = gcp_object_real_submit_print_job;
}

GHashTable *
gcp_object_get_printers (GCPObject *self, const gchar *access_token, const gchar *connection_status)
{
  g_return_val_if_fail (GCP_IS_OBJECT (self), NULL);

  GCPObjectClass *klass = GCP_OBJECT_GET_CLASS (self);
  const gchar *printers = klass->get_printers (self, access_token, connection_status);

  JsonObject *jobject = json_data_get_root (printers);
  JsonArray *jarray = get_array_from_json_object (jobject, "printers");
  GHashTable *printer_id_name_pairs = get_ghashtable_for_id_and_value_in_json_array (jarray, "id", "displayName");

  return printer_id_name_pairs;
}

GHashTable *
gcp_object_get_printer_options (GCPObject   *self,
                                const gchar *uid,
                                const gchar *access_token)
{
  g_return_val_if_fail (GCP_IS_OBJECT (self), NULL);

  GCPObjectClass *klass = GCP_OBJECT_GET_CLASS (self);
  const gchar *printer_options_json = klass->get_printer_options (self, uid, access_token);
  JsonObject *root = json_data_get_root (printer_options_json);
  JsonArray *jarray = get_array_from_json_object (root, "printers");
  JsonNode *jnode = json_array_get_element (jarray, 0);
  JsonObject *jobject = json_node_get_object (jnode);
  JsonNode *capabilities_node = json_object_get_member (jobject, "capabilities");
  JsonObject *capabilities_obj = json_node_get_object (capabilities_node);
  JsonNode *printer_node = json_object_get_member (capabilities_obj, "printer");
  JsonObject *printer_options = json_node_get_object (printer_node);
  JsonArray *vendor_capability = get_array_from_json_object (printer_options, "vendor_capability");
  GHashTable *vendor_capability_hashtable = get_vendor_capability_hashtable (vendor_capability);
  
  return vendor_capability_hashtable;
}

gboolean
gcp_object_submit_print_job (GCPObject   *self,
                             const gchar *uid,
                             const gchar *access_token,
                             const gchar *title,
                             const gchar *ticket)
{
  g_return_val_if_fail (GCP_IS_OBJECT (self), FALSE);

  GCPObjectClass *klass = GCP_OBJECT_GET_CLASS (self);
  gboolean res = FALSE;
  res = klass->submit_print_job (self, uid, access_token, title, ticket);

  return res;
}

/*****************************************************************************/

const gchar *
gcp_object_real_get_printers (GCPObject *self,
                              const gchar *access_token,
                              const gchar *connection_status)
{
  RestProxy *proxy;
  RestProxyCall *call;

  const gchar *header = "X-CloudPrint-Proxy";
  const gchar *header_value = "Common Printing Dialog";
  const gchar *method = "GET";
  const gchar *function = "search";
  const gchar *param1_name = "access_token";

  gboolean res = FALSE;

  proxy = rest_proxy_new ("https://www.google.com/cloudprint/", FALSE);
  call = rest_proxy_new_call (proxy);
  if (connection_status != NULL)
    res = make_api_request (proxy, &call, method, function, header, header_value, param1_name, access_token, "connection_status", connection_status, NULL);
  else
    res = make_api_request (proxy, &call, method, function, header, header_value, param1_name, access_token, NULL);

  const gchar *printers;

  if (res)
  {
    printers = rest_proxy_call_get_payload (call);
  }
  else
  {
    printers = g_strdup("API request failed!");
  }

  /* TODO: Error handling in case something goes wrong. */

  return printers;
}

const gchar *
gcp_object_real_get_printer_options (GCPObject   *self,
                                     const gchar *uid,
                                     const gchar *access_token)
{
  RestProxy *proxy;
  RestProxyCall *call;

  const gchar *header = "X-CloudPrint-Proxy";
  const gchar *header_value = "Common Printing Dialog";
  const gchar *method = "GET";
  const gchar *function = "printer";
  const gchar *param1_name = "access_token";
  const gchar *param2_name = "printerid";

  gboolean res = FALSE;

  proxy = rest_proxy_new ("https://www.google.com/cloudprint/", FALSE);
  call = rest_proxy_new_call (proxy);
  res = make_api_request (proxy, &call, method, function, header, header_value, param1_name, access_token, param2_name, uid, NULL);

  const gchar *printer_options;

  if (res)
  {
    printer_options = rest_proxy_call_get_payload (call);
  }
  else
  {
    printer_options = g_strdup("API request failed!");
  }

  /* TODO: Error handling in case something goes wrong. */

  return printer_options;
}

gboolean
gcp_object_real_submit_print_job (GCPObject   *self,
                                  const gchar *uid,
                                  const gchar *access_token,
                                  const gchar *title,
                                  const gchar *ticket)
{
  /* TODO: Make api request to submit a file for printing. */
  return TRUE;
}
