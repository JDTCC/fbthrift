/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.facebook.thrift.runner;

import com.facebook.thrift.client.ThriftClientConfig;
import com.facebook.thrift.example.ping.PingService;
import com.facebook.thrift.example.ping.PingServiceReactiveAsyncWrapper;
import com.facebook.thrift.example.ping.PingServiceReactiveClient;
import com.facebook.thrift.legacy.client.LegacyRpcClientFactory;
import io.netty.util.ResourceLeakDetector;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.time.Duration;
import java.util.concurrent.TimeUnit;
import org.apache.thrift.ProtocolId;

public class AsyncWrapperClient extends AbstractAsyncClient {
  public static void main(String... args) {
    ResourceLeakDetector.setLevel(ResourceLeakDetector.Level.DISABLED);
    if (args.length < 3) {
      throw new IllegalArgumentException(
          "Incorrect number of arguments. <hostname> <port> <warmupSeconds> <benchmarkSeconds>");
    }
    String host = args[0];
    int port = Integer.parseInt(args[1]);
    int warmupSeconds = Integer.parseInt(args[2]);
    int benchmarkSeconds = Integer.parseInt(args[3]);

    AsyncWrapperClient c = new AsyncWrapperClient();
    c.runTest(
        new InetSocketAddress(host, port),
        Duration.ofSeconds(warmupSeconds),
        Duration.ofSeconds(benchmarkSeconds));
  }

  @Override
  protected PingService.Async getClient(SocketAddress address) {
    LegacyRpcClientFactory rpcClientFactory =
        new LegacyRpcClientFactory(
            new ThriftClientConfig()
                .setDisableSSL(true)
                .setRequestTimeout(io.airlift.units.Duration.succinctDuration(1, TimeUnit.DAYS)));

    PingServiceReactiveClient reactiveClient =
        new PingServiceReactiveClient(
            ProtocolId.BINARY, rpcClientFactory.createRpcClient(address).cache());

    return new PingServiceReactiveAsyncWrapper(reactiveClient);
  }
}
