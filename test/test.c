/*
 * @Author: jiejie
 * @Github: https://github.com/jiejieTop
 * @Date: 2019-12-11 21:53:07
 * @LastEditTime: 2020-05-07 19:16:05
 * @Description: the code belongs to jiejie, please keep the author information and source code according to the license.
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>
#include "httpclient.h"
#include <http_interceptor.h>

extern const char *test_ca_get();

#define URL "http://jiejie:test@jiedev.com/test/index.php?who=jiejie&is=test#frag"
#define URL1 "https://jiejie:test1@jiedev1.com/test1/index.php?who=jiejie1&is=test#frag1"


int main(void)
{
    http_interceptor_t interceptor;

    memset(&interceptor, 0, sizeof(http_interceptor_t));

    http_log_init();

    // HTTP_LOG_I("url:%s", URL);
    
    http_url_parsing(&interceptor.connect_params, URL);

    // HTTP_LOG_I("host:%s", http_get_connect_params_host(&interceptor.connect_params));
    // HTTP_LOG_I("port:%d", http_get_connect_params_port(&interceptor.connect_params));
    // HTTP_LOG_I("scheme:%s", http_get_connect_params_scheme(&interceptor.connect_params));
    // HTTP_LOG_I("user:%s", http_get_connect_params_user(&interceptor.connect_params));
    // HTTP_LOG_I("password:%s", http_get_connect_params_password(&interceptor.connect_params));
    // HTTP_LOG_I("path:%s", http_get_connect_params_path(&interceptor.connect_params));
    // HTTP_LOG_I("query:%s", http_get_connect_params_query(&interceptor.connect_params));
    // HTTP_LOG_I("farg:%s\n", http_get_connect_params_farg(&interceptor.connect_params));

    http_request_init(&interceptor.request);
    http_request_header_init(&interceptor.request);
    http_request_add_header_form_index(&interceptor.request, HTTP_REQUEST_HEADER_HOST, http_get_connect_params_host(&interceptor.connect_params));
    // http_request_set_version(&interceptor.request, "HTTP/2.0");
    HTTP_LOG_I("head:%s", http_request_get_header_form_index(&interceptor.request, HTTP_REQUEST_HEADER_HOST));
    http_request_set_method(&interceptor.request, HTTP_REQUEST_METHOD_GET);
    http_request_start_line(&interceptor.request, interceptor.connect_params.http_path);
    http_request_print_start_line(&interceptor.request);
    http_request_print_header(&interceptor.request);

    
    sleep(2);

    return 0;
}