#include <curl/curl.h>

int main(int argc, char *argv[])
{
  CURLcode ret;
  CURL *hnd;
  struct curl_slist *headers;

  headers = NULL;
  headers = curl_slist_append(headers, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
  headers = curl_slist_append(headers, "Accept-Language: en-US,en;q=0.5");
  headers = curl_slist_append(headers, "Connection: keep-alive");
  headers = curl_slist_append(headers, "Cookie: __cfduid=d2968dfaa76dada580b923fac7e093d061571294263; AWSALB=Uu9vE1HnWlW5TXbouXY0sTfE4qQRtz03MnAAKwQTmhIxtoB31dYXFN6PIpEcdUjphZ+i/ynkJ4he6kFw0X5CFQ8LpRUhR5YbSxUhlBb2zododhGDFcq+UOvX8hka; Unique_ID_v2=d316b882e38649459fe3a24112658486; __cf_bm=e916e894150611cfd4a67e54c805e5e09eaab98b-1571294263-1800-AWCGwtWV/1I1oFisZ7DplVhsoDuIV8fNBu+htwA+La56jXRF9No3bdeQgM0rdTUy7hC7GQmU8ZtswVHONBzsl2I=; ResponsiveSwitch.DesktopMode=1");
  headers = curl_slist_append(headers, "Upgrade-Insecure-Requests: 1");
  headers = curl_slist_append(headers, "Cache-Control: max-age=0");
  headers = curl_slist_append(headers, "TE: Trailers");

  hnd = curl_easy_init();
  curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
  curl_easy_setopt(hnd, CURLOPT_URL, "https://kick.com/api/v2/channels/silentdevnull/");
  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(hnd, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64; rv:69.0) Gecko/20100101 Firefox/69.0");
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt(hnd, CURLOPT_ACCEPT_ENCODING, "");
  curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);

  ret = curl_easy_perform(hnd);

  curl_easy_cleanup(hnd);
  hnd = NULL;
  curl_slist_free_all(headers);
  headers = NULL;

  return (int)ret;
}
