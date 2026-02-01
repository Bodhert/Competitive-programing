defmodule RationalNumbers do
  @type rational :: {integer, integer}

  @doc """
  Add two rational numbers
  """
  @spec add(a :: rational, b :: rational) :: rational
  def add({num1, dem1}, {num2, dem2}) do
    reduce({num1 * dem2 + num2 * dem1, dem1 * dem2})
  end

  @doc """
  Subtract two rational numbers
  """
  @spec subtract(a :: rational, b :: rational) :: rational
  def subtract({num1, dem1}, {num2, dem2}) do
    reduce({num1 * dem2 - num2 * dem1, dem1 * dem2})
  end

  @doc """
  Multiply two rational numbers
  """
  @spec multiply(a :: rational, b :: rational) :: rational
  def multiply({num1, dem1}, {num2, dem2}) do
    reduce({num1 * num2, dem1 * dem2})
  end

  @doc """
  Divide two rational numbers
  """
  @spec divide_by(num :: rational, den :: rational) :: rational
  def divide_by({num1, dem1}, {num2, dem2}) do
    reduce({num1 * dem2, dem1 * num2})
  end

  @doc """
  Absolute value of a rational number
  """
  @spec abs(a :: rational) :: rational
  def abs({num, dem}) do
    reduce({Kernel.abs(num), Kernel.abs(dem)})
  end

  @doc """
  Exponentiation of a rational number by an integer
  """
  @spec pow_rational(a :: rational, n :: integer) :: rational
  def pow_rational({num, dem}, n) when n >= 0 do
    reduce({Integer.pow(num, n), Integer.pow(dem, n)})
  end

  def pow_rational({num, dem}, n) do
    n = Kernel.abs(n)
    reduce({Integer.pow(dem, n), Integer.pow(num, n)})
  end

  @doc """
  Exponentiation of a real number by a rational number
  """
  @spec pow_real(x :: integer, n :: rational) :: float
  def pow_real(x, {num, dem}) do
    Float.pow(x / 1.0, num / dem)
  end

  @doc """
  Reduce a rational number to its lowest terms
  """
  @spec reduce(a :: rational) :: rational
  def reduce({num, dem}) do
    gcd = Integer.gcd(num, dem)
    standard_form({num / gcd, dem / gcd})
  end

  @spec standard_form(a :: rational) :: rational
  defp standard_form({num, dem}) when dem < 0 do
    {num * -1, dem * -1}
  end

  defp standard_form(rational), do: rational
end
