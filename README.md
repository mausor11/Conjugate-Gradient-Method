# 🔢 Conjugate Gradient Method

This project implements the **Conjugate Gradient Method** in Python — a powerful iterative algorithm for solving systems of linear equations of the form **Ax = b**, especially when A is large, sparse, symmetric, and positive-definite.

## 📘 What is the Conjugate Gradient Method?

The Conjugate Gradient (CG) algorithm is used primarily in numerical linear algebra to solve large systems without explicitly computing matrix inverses.

- It's more efficient than Gaussian elimination for large sparse matrices.
- It converges in at most `n` steps (for an `n x n` matrix), though usually much faster.

## 🧠 Key Features

- Works with symmetric positive-definite matrices
- Iterative solution without direct matrix inversion
- Custom stopping criteria based on tolerance or number of iterations
- Clean, readable Python code with comments for learning purposes

## 📦 Dependencies

```bash
numpy
```

Install with:

```bash
pip install numpy
```

## 🚀 How to Run

```bash
python conjugate_gradient.py
```

You can customize:
- Matrix `A`
- Vector `b`
- Initial guess `x0`
- Maximum iterations and tolerance

## 📈 Example Output

```
Iteration 0: Residual norm = 3.7416
Iteration 1: Residual norm = 0.5831
Iteration 2: Residual norm = 0.1234
...
Converged after 5 iterations
```

## 📄 License

MIT License – free to use, share, and learn from.

---

> 🎓 This project was created for academic purposes, to explore numerical methods and optimization in Python.
