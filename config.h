#pragma once

// ═══════════════════════════════════════════════════════════════
//  config.h  —  Sats ATM static configuration
//
//  Operator credentials (Blink wallet ID, API key, WiFi) are
//  stored at runtime via the settings screen and persisted in
//  ESP32 Preferences (NVS flash). They do NOT live here.
//
//  This file contains only hardware constants and AP settings
//  that never change between deployments.
// ═══════════════════════════════════════════════════════════════

// ── Access Point (tablet connects here) ─────────────────────────
#define AP_SSID        "SatsATM"          // tablet WiFi network name
#define AP_PASSWORD    "lightning"         // min 8 chars for WPA2
#define AP_IP          "192.168.4.1"      // fixed AP gateway IP

// ── Coin acceptor ────────────────────────────────────────────────
#define COIN_PIN       4                  // GPIO connected to PC817 output
#define PULSES_PER_EUR 10                 // pulses = 1 euro (HX-916 config)
#define MAX_CREDIT_EUR 10.0f              // maximum credit per session (€)
#define MAX_PULSES     200                // sanity cap: ~€20 worth of pulses

// ── Timing ───────────────────────────────────────────────────────
#define INTER_COIN_MS  2500               // ms gap before session is finalised
#define BALANCE_POLL_MS   15000           // wallet balance poll interval

// ── Blink API ────────────────────────────────────────────────────
#define BLINK_API_URL  "https://api.blink.sv/graphql"

// ── Fuel gauge thresholds (fraction of starting balance) ─────────
#define GAUGE_HIGH     0.66f              // > 66%  → all green
#define GAUGE_MID      0.33f              // > 33%  → amber
#define GAUGE_LOW      0.10f              // > 10%  → red
                                          // ≤ 10%  → red flashing
