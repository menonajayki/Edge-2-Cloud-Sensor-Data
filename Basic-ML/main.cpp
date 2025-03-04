// main.cpp
#include <iostream>
#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/framework/tensor.h"

int main() {
    using namespace tensorflow;
    using namespace tensorflow::ops;

    // Create a root scope for building the graph.
    Scope root = Scope::NewRootScope();

    // Define a placeholder for the input 'X' (a single float value).
    auto X = Placeholder(root.WithOpName("X"), DT_FLOAT);

    // Build the graph: Y = (2 * X) + 1.
    auto two = Const(root.WithOpName("two"), 2.0f);
    auto one = Const(root.WithOpName("one"), 1.0f);
    auto product = Mul(root.WithOpName("product"), two, X);
    auto Y = Add(root.WithOpName("Y"), product, one);

    // Create a session to run the graph.
    ClientSession session(root);

    // Create an input tensor for X with a value of 3.0.
    Tensor input_tensor(DT_FLOAT, TensorShape({1}));
    input_tensor.flat<float>()(0) = 3.0f;

    // Run the graph to compute Y.
    std::vector<Tensor> outputs;
    TF_CHECK_OK(session.Run({{X, input_tensor}}, {Y}, &outputs));

    // Print the result.
    std::cout << "For input x = 3, y = " << outputs[0].scalar<float>()() << std::endl;
    return 0;
}
